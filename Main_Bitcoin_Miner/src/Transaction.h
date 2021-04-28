/*
 * transaction.h
 *
 *  Created on: Apr 27, 2021
 *      Author: Anurag
*/

#ifndef SRC_TRANSACTION_H_
#define SRC_TRANSACTION_H_

#include <cstdint>
#include <iostream>
#include "DHTSensor.h"

using namespace std;

class Transaction{
	public:
		uint32_t _ntIndex;
		string _prevtHash;
		string _destAddr;
		Transaction();
		Transaction(DHTSensor tdata);
		string GetHash();
		string GetSAddr();
		string GetDAddr();
		DHTSensor GetData();
		string _CalculatetHash();
	private:
		string _sourceAddr;
		DHTSensor _tData;
		time_t _ttTime;
		string _tHash;
};

#endif /* SRC_TRANSACTION_H_ */

