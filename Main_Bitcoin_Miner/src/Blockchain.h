/*
 * Blockchain.h
 *
 *  Created on: Mar 11, 2021
 *      Author: Anurag
 */

#ifndef BLOCKCHAIN_H_
#define BLOCKCHAIN_H_

#include <cstdint>
#include <vector>
#include "Block.h"
using namespace std;

class Blockchain {
	public:
		Blockchain();
		void AddBlock(Block bNew);
		Block _GetLastBlock() const;
		void DisplayBlockchain();
	private:
		uint32_t _nDifficulty;
		vector<Block> _vChain;

};


#endif /* BLOCKCHAIN_H_ */
