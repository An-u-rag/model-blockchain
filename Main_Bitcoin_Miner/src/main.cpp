/*
 * main.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: Anurag
 */

#include "Blockchain.h"
#include <ctime>
#include "global.h"


int main()
{
	Blockchain bChain = Blockchain();

	cout<<"Mining block 1....."<<endl;
	sTime = time(NULL);
	bChain.AddBlock(Block(1,"1FtA9hqz2jbjEx6XJ5eeBd6DRZ7xwpj5tL", time(nullptr)));

//	cout<<"Mining block 2....."<<endl;
//	sTime = time(NULL);
//	bChain.AddBlock(Block(2,"Block 2 Data"));

//	cout<<"Mining block 3....."<<endl;
//	sTime = time(NULL);
//	bChain.AddBlock(Block(3,"Block 3 Data"));

	return 0;
}


