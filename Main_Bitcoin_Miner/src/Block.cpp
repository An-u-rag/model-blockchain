/*
 * Block.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: Anurag
 */

#include "Block.h"
#include "SHA256.h"
#include <ctime>
#include <sstream>
#include "global.h"


Block::Block(uint32_t nIndexIn, const string &sDataIn, time_t tTimeIn){
	_nIndex = nIndexIn;
	_sData = sDataIn;
	_tTime = tTimeIn;
	_nNonce = -1;

}

string Block::GetHash() {
	return _sHash;
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
		cout<<"Hash with nonce "<<_nNonce<<" : "<< _sHash<<endl;
	}while(_sHash.substr(0,nDifficulty) != str);

	cout<<"Block mined: " << _sHash <<endl;
	cout<<"Time taken: "<< time(NULL)-sTime<<" seconds"<<endl;

}

inline string Block::_CalculateHash() const {
	stringstream ss;
	ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

	return sha256(ss.str());
}



