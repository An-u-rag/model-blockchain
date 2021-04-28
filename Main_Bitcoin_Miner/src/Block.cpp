/*
 * Block.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: Anurag
 */

#include "Block.h"
#include "Transaction.h"
#include "SHA256.h"
#include <ctime>
#include <sstream>
#include "global.h"

Block::Block(){
	_sHash = "GENESIS BLOCK HASH";
	_tTime = time(nullptr);
	_nIndex = 0;
}

Block::Block(uint32_t nIndexIn, Transaction sDataIn, time_t _tTimeIn){
	_nIndex = nIndexIn;
	_sData = sDataIn;
	_tTime = _tTimeIn;
	_nNonce = -1;
}

string Block::GetHash() {
	return _sHash;
}

Transaction Block::GetTransaction(){
	return _sData;
}

void Block::DisplayBlock(){
	if(_nIndex == 0){
		cout<<endl<<"//////////////BLOCK///////////////"<<endl;
		cout<<"Block number: "<<_nIndex<<endl;
		cout<<"Block creation time: "<<_tTime<<endl;
		cout<<"Block hash: "<<_sHash<<endl;
	} else {
	cout<<endl<<"//////////////BLOCK///////////////"<<endl;
	cout<<"Block number: "<<_nIndex<<endl;
	cout<<"Block Previous Hash: "<<sPrevHash<<endl;
	cout<<"Block creation time: "<<_tTime<<endl;
	cout<<"Block hash: "<<_sHash<<endl;
	cout<<"***Block Transaction Details: "<<endl;
	cout<<"Transaction Hash: "<<_sData.GetHash()<<endl;
	cout<<"Transaction Sensor Data: "<<_sData.GetData().GetTemp()<<" + "<< _sData.GetData().GetHumidity()<<endl<<"//////////////////////////////"<<endl;
	}
}

void Block::MineBlock(uint32_t nDifficulty){
	char cstr[nDifficulty + 1];
	for(uint32_t i=0;i<nDifficulty;++i){
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	string str(cstr);

	do{
		_nNonce++;
		_sHash = _CalculateHash();
		//cout<<"Hash with nonce "<<_nNonce<<" : "<< _sHash<<endl;
	}while(_sHash.substr(0,nDifficulty) != str);

	cout<<"Block mined: " << _sHash <<endl;
	cout<<"Time taken: "<< time(NULL)-_tTime<<" seconds"<<endl;
	cout <<"Transaction address data: "<< _sData.GetSAddr()<<"-->"<<_sData.GetDAddr();
}

inline string Block::_CalculateHash() {
	stringstream ss;
	string transHash = _sData.GetHash();
	ss << _nIndex << _tTime << transHash << _nNonce << sPrevHash;

	return sha256(ss.str());
}



