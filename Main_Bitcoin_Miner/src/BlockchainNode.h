/*
 * BlockchainNode.h
 *
 *  Created on: Apr 28, 2021
 *      Author: Anurag
 */

#ifndef SRC_BLOCKCHAINNODE_H_
#define SRC_BLOCKCHAINNODE_H_

#include "Blockchain.h"
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

class BlockchainNode {
public:
	Blockchain bChain;
	BlockchainNode();
	BlockchainNode(string ipAddr, int nodeIndex, int blockCount);
	string GetIP();
	float GetFB();
	void sendTransaction(Transaction t,time_t sTime,int cnc);
	int GetBlockCount();
	int GetNodeIndex();
	void StartBlockchain();
	void updateTransactionandAddBlock(time_t sTime);
private:
	string _ipAddr;
	float _frequencyBand;
	int _nodeIndex;
	int _blockCount;
	static int nodeCount;
	static map<string,int> temp_transmap;
	static int maxCount;
	static Transaction maxLeader;
};

#endif /* SRC_BLOCKCHAINNODE_H_ */
