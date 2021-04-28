/*
 * BlockchainNode.cpp
 *
 *  Created on: Apr 28, 2021
 *      Author: Anurag
 */

#include "BlockchainNode.h"
#include "Block.h"
#include <ctime>
#include "global.h"

map<string,int> BlockchainNode::temp_transmap;
int BlockchainNode::maxCount;
Transaction BlockchainNode::maxLeader;
int BlockchainNode::nodeCount;


BlockchainNode::BlockchainNode() {
	_ipAddr = "----------";
	_nodeIndex = 0;
	_blockCount = 0;
	nodeCount = 0;
}

BlockchainNode::BlockchainNode(string ipAddr, int nodeIndex, int blockCount){
	_ipAddr = ipAddr;
	_nodeIndex = nodeIndex;
	_blockCount = blockCount;
	_frequencyBand = 2.4;
	nodeCount = 0;
}

void BlockchainNode::StartBlockchain(){
	bChain = Blockchain();
}

void BlockchainNode::sendTransaction(Transaction t, time_t sTime,int cnc){

	nodeCount++;
	// Validating the transaction with Majority and Proof of Work will be executed when the Block is being created.

	// Majority
	// finding existing top count
	map<string,int>::iterator i;
	if(!temp_transmap.empty()){
		for(i = temp_transmap.begin();i != temp_transmap.end(); ++i){
			if(i->second > maxCount){
				maxCount = i->second;
				maxLeader = t;
			}
		}
	}else{
		maxCount = 1;
		maxLeader = t;
	}
	if(t.GetHash()!=" " && temp_transmap.empty()){
		temp_transmap.insert(pair<string,int>(t.GetHash(),1));
	} else if(temp_transmap.find(t.GetHash())==temp_transmap.end()){
		temp_transmap.insert(pair<string,int>(t.GetHash(),1));
	} else {
		maxCount++;
		maxLeader = t;
		temp_transmap.at(t.GetHash())++;
	}
	cout<<"The current received Transaction Hashes with their count: ";
	for(i = temp_transmap.begin();i != temp_transmap.end(); ++i){
		cout<< endl<< i->first<<"---"<<i->second<< endl;
	}
	cout<<endl;
	cout <<"Majority number of Hashes: "<< maxCount <<endl<<"The current Leading Majority Hash: "<< maxLeader.GetHash()
			<<endl<<"------------------------------------------------"<<endl;

	// find by value from map
	std::vector<std::string> vec;
	bool bResult = false;
	auto it = temp_transmap.begin();
	// Iterate through the map
	while(it != temp_transmap.end()){
		// Check if value of this entry matches with given value
		if(it->second == maxCount)
		{
			// Yes found
			bResult = true;
			// Push the key in given map
			vec.push_back(it->first);
		}
		// Go to next entry in map
		it++;
	}
	if(bResult && vec.size() > 1){
		for(auto elem : vec)
		{
			cout<<"equal count : Forking....for hash: ";
			cout<<elem<<endl<<endl;
		}
	}
	cout << "*******************************Transaction End***********************************"<<endl;
	if(nodeCount == cnc){
		cout <<endl<< "\t Synchronizing Blockchain"<<endl<<"***************************************"<<endl;
		cout << "Node number : "<<nodeCount<<" Transmiting correct transaction after Majority...";
		for(int i=0;i<n;i++){
			nodeList[i].updateTransactionandAddBlock(sTime);
		}
		cout<<"Closest Nodes Synchronized! Synchronizing Blockchain Network..."<<endl;
	}
}

string BlockchainNode::GetIP(){
	return _ipAddr;
}

float BlockchainNode::GetFB(){
	return _frequencyBand;
}
int BlockchainNode::GetBlockCount(){
	return _blockCount;
}
int BlockchainNode::GetNodeIndex(){
	return _nodeIndex;
}

void BlockchainNode::updateTransactionandAddBlock(time_t sTime){
	_blockCount++;
	maxLeader._destAddr = _ipAddr;
	cout<<"Adding Block with transaction from sensor with time: "<< sTime <<endl;
	bChain.AddBlock(Block(_blockCount,maxLeader,sTime));
	cout<<endl<<"The transaction has of block is : "<<bChain._GetLastBlock().GetTransaction().GetHash()<<endl<<endl;
}
