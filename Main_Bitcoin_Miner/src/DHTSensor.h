/*
 * DHTSensor.h
 *
 *  Created on: Apr 27, 2021
 *      Author: Anurag
 */

#ifndef SRC_DHTSENSOR_H_
#define SRC_DHTSENSOR_H_

#include <iostream>
#include <cstdint>

using namespace std;

class DHTSensor {
	public:
		DHTSensor();
		DHTSensor(string ipAddr, float freq);
		float GetTemp();
		float GetHumidity();
		string GetIP();
		float GetFB();
		void Sense(float temp, float humidity);
	private:
		string _ipAddr;
		float _frequencyBand;
		float _temperature;
		float _humidity;
};

#endif /* SRC_DHTSENSOR_H_ */
