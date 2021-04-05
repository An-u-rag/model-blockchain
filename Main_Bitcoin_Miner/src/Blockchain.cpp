/*
 * Blockchain.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: Anurag
 */

#include "Blockchain.h"
#include <ctime>

Blockchain::Blockchain(){
	_vChain.emplace_back(Block(0,"1M4nbeLFKgB9tnGgEAQbChq7kpJvUaWWxJ",time(nullptr)));
	_nDifficulty = 4;
}

void Blockchain::AddBlock(Block bNew){
	bNew.sPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
	return _vChain.back();
}
