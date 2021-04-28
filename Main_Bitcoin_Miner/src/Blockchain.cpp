/*
 * Blockchain.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: Anurag
 */

#include "Blockchain.h"
#include "Transaction.h"
#include <ctime>

Blockchain::Blockchain(){
	_vChain.emplace_back(Block());
	_nDifficulty = 4;
}

void Blockchain::AddBlock(Block bNew){
	bNew.sPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

void Blockchain::DisplayBlockchain(){
	for(auto it = _vChain.begin(); it != _vChain.end(); it++){
		it -> DisplayBlock();
	}
}

Block Blockchain::_GetLastBlock() const {
	return _vChain.back();
}
