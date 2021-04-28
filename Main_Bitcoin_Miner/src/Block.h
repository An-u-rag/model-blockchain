/*
 * Block.h
 *
 *  Created on: Mar 11, 2021
 *      Author: Anurag
 */

#ifndef BLOCK_H_
#define BLOCK_H_
#include "Transaction.h"
#include <cstdint>
#include <iostream>

using namespace std;

class Block{


public:
	string sPrevHash;
	Block();
	Block(uint32_t nIndexIn, Transaction sDataIn, time_t _tTimeIn);
	string GetHash();
	void MineBlock(uint32_t nDifficulty);
	Transaction GetTransaction();
	void DisplayBlock();
private:
	uint32_t _nIndex;
	int64_t _nNonce;
	Transaction _sData;
	string _sHash;
	time_t _tTime;
	string _CalculateHash();
};





#endif /* BLOCK_H_ */
