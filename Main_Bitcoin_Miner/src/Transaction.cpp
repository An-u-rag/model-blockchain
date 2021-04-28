/*
 * Transaction.cpp
 *
 *  Created on: Apr 27, 2021
 *      Author: Anurag
 */

#include "Transaction.h"
#include "DHTSensor.h"
#include "SHA256.h"
#include <ctime>
#include <sstream>
#include "global.h"

Transaction::Transaction(){
	_ntIndex = 1;
	_sourceAddr = "00000";
	_destAddr = "00000";
	_ttTime = time(nullptr);
	_tHash = _CalculatetHash();
}
Transaction::Transaction(DHTSensor tdata){
	_ntIndex = 1;
	_tData = tdata;
	_ttTime = time(nullptr);
	_sourceAddr = tdata.GetIP();
	_tHash = _CalculatetHash();
}

string Transaction::GetHash() {
	return _tHash;
}

string Transaction::GetSAddr() {
	return _sourceAddr;
}

string Transaction::GetDAddr() {
	return _destAddr;
}

DHTSensor Transaction::GetData() {
	return _tData;
}

inline string Transaction::_CalculatetHash(){
	stringstream ss;
	float humiditySensor = _tData.GetHumidity();
	float tempSensor = _tData.GetTemp();
	ss << _ntIndex << tempSensor << humiditySensor << _prevtHash;

	return sha256(ss.str());
}

