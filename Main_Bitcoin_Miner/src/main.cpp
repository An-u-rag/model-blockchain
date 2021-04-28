/*
 * main.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: Anurag
 */

#include "Blockchain.h"
#include "BlockchainNode.h"
#include "Transaction.h"
#include "DHTSensor.h"
#include <ctime>
#include <cstdint>
#include "global.h"


int main()
{
//  The Below commented values are global variables.
//	int n = 5;
//	BlockchainNode nodeList[n];
//	Blockchain bChain = Blockchain();


// IP address allocation for Decentralized nodes for Internet Protocol over 2.4 GHz.
	for(int i=0;i<n;i++){
		string subnetIP = "192.168.0";
		string blockIP = std::to_string(i+1);
		nodeList[i] = BlockchainNode(subnetIP+"."+blockIP, i+1, 0);
		nodeList[i].StartBlockchain();
	}


// DHTSensor Initialization for gathering temperature and humidity data.
	DHTSensor sensor = DHTSensor("192.169.5.1", 2.4);
// Function call to capture and sense data.
	sensor.Sense(50.5, 20.4);


// The below variable is used to identify closest nodes in the Blockchain Node Network for the Sensor.
//	Here the value is arbitrarily taken as 3.
	int closeNodeCount = 3;

// Current time is recorded before Data is sent from IoT sensor/gateway.
	time_t sTime = time(NULL);

		// Correct Transaction**
		Transaction test = Transaction(sensor);

		// Corrupt Sensor/Hacker/Intruder/Malfunction**
		DHTSensor corrupt_sensor = DHTSensor("192.169.5.1",2.4);
		// manual corruption of a Transaction to one of the nodes in the blockchain.
		corrupt_sensor.Sense(10.0,30.0); // Manipulated values of the sensor.
		Transaction corrupt_test = Transaction(corrupt_sensor);


		// Case 2 : Second Transmitted transaction to node 2 is corrupted by an external entity(Intruder).

		// Transmitting correct transaction to node 1.
		nodeList[0].StartBlockchain();
		nodeList[0].sendTransaction(test,sTime,closeNodeCount);

		// Transmitting transaction to node 2. Corrupt transaction received by node 2.
		nodeList[1].StartBlockchain();
		nodeList[1].sendTransaction(corrupt_test,sTime,closeNodeCount);

		// Transmitting correct transaction to node 3.
		nodeList[2].StartBlockchain();
		nodeList[2].sendTransaction(test,sTime,closeNodeCount);

		// Printing the Blockchain from one node i.e. Node number 1, 2, 5. This Blockchain is the same over the network of decentralized nodes due to the Synchronization.
		// Synchronization takes the majority transaction and updates the Blockchain Network.
		cout<<endl<<"/*/*/*/*/*/BLOCKCHAIN of NODE 1/*/*/*/*/*/"<<endl;
		nodeList[0].bChain.DisplayBlockchain();

		cout<<endl<<"/*/*/*/*/*/BLOCKCHAIN of NODE 2(Corrupted Information)/*/*/*/*/*/"<<endl;
		nodeList[1].bChain.DisplayBlockchain();

		cout<<"/*/*/*/*/*/BLOCKCHAIN of NODE 5(External Node)/*/*/*/*/*/"<<endl;
		nodeList[4].bChain.DisplayBlockchain();

	return 0;
}





//	for(int i=0;i<closeNodeCount;i++){
//		Transaction test = Transaction(sensor, nodeList[i].GetIP());
//		nodeList[i].StartBlockchain();
//		nodeList[i].sendTransaction(test,sTime);
//	}


//  cout<<"Adding Block 1 with transaction from sensor"<<endl;
//	sTime = time(NULL);
//	bChain.AddBlock(Block(1,test, time(nullptr)));
//	cout << endl << test.GetData().GetHumidity();


//	cout<<"Mining block 2....."<<endl;
//	sTime = time(NULL);
//	bChain.AddBlock(Block(2,"Block 2 Data"));

//	cout<<"Mining block 3....."<<endl;
//	sTime = time(NULL);
//	bChain.AddBlock(Block(3,"Block 3 Data"));

