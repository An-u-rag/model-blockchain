/*
 * DHTSensor.cpp
 *
 *  Created on: Apr 27, 2021
 *      Author: Anurag
 */

#include "DHTSensor.h"
#include <iostream>

DHTSensor::DHTSensor() {
	_ipAddr = "00000";
	_frequencyBand = 0.0;
}

DHTSensor::DHTSensor(string ipAddr, float freq) {
	_ipAddr = ipAddr;
	_frequencyBand = freq;
}

void DHTSensor::Sense(float temp,float humidity){
	_temperature = temp;
	_humidity = humidity;
}

float DHTSensor::GetTemp(){
	return _temperature;
}
float DHTSensor::GetHumidity(){
	return _humidity;
}
string DHTSensor::GetIP(){
	return _ipAddr;
}
float DHTSensor::GetFB(){
	return _frequencyBand;
}
