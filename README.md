This code is an implementation of a proposed integration of Blockchain Network in an IOT system with focus on Securiy. 

This was developed as a part of the research paper "Implementing Security in IOT Systems Via Blockchain" written by:
1. Anurag Parcha
2. Sanjana Mishra
3. Aditya Bist
4. Reema Agarwal
5. Sagar Gupta
6. Saahil Sharma

Prerequisites :-
1. Language : C++
2. OS : Windows
3. Preferred IDE : Eclipse for C++ / Visual Studio

To compile and execute this code:
1. Clone the repository directly OR download the contents of this repo onto your PC. Make sure to remember the location of the downloaded folder.
2. Open the same downloaded folder(Main_Bitcoin_Miner) from your IDE; preferably Eclipse for C++.
  -> Click "Open Projects Fom File System" 
  -> to the right of "Import Source", click "Directory" 
  -> Select the downloaded folder "Main_Bitcoin_Miner" from Step 1.
  -> Click Finish.
3. Now the code should be visible.
4. The code can be executed by pressing the green run icon located at top left corner.

Cases to consider incase of an error:
1. Make sure that the Eclipse IDE version is up to date.
2. Make sure that the Eclipse IDE is linked to a C++ complier in the settings. GNU C++ Compiler is recommended. 
3. If the error is thrown that a required module is not found during run time, please download it and try again.

To replicate the Secuity Cases shown in the Research paper:
All required changes only need to be made in "main.cpp" and not in any other file.

Before we can modify, its best to understand the important terms from the code.

Classes: 
1. DHTSensor : This is a class which represents a weather monitoring system's DHT sensor which records temperature and humidity.
2. BlockchainNode : This is a Class which represents a decentralised node on the blockchain network.
3. Blockchain : This is a class which refers to a Blockchain running on each of the decentralised nodes i.e. BlockChainNode objects.
4. Block : Refers to an individual Block on a blockchain which has transactions.
5. Transaction: This is a class which refers to a transaction made between the DHT sensor object and the decentralised node's blockchain object.

Variables:
1. n - This is a global variable referring to the number of Decentralized nodes in the blockchain network, default is 5.(This value can be changes on the "global.cpp" file)
2. nodeList[] - This is an object array which represents all the decentralised nodes on the blockchain network that is all the objects of BlockChainNode Class. Size depends on value of n.
3. sensor - The actual and true object of DHTSensor object. 
4. corrupt_sensor - An object of DHTSensor whose value has been adulterated or modified by an external source like a hacker.
5. closeNodeCount - This integer value tells the amount of nodes the sensor is directly connected to and to whom it will relay its transmisions to.
6. sTime - This is a timestamp variable which records the time before the initiation of a transaction.
7. test - The pure transaction which the sensor wants to relay to the blockchain network.
8. corrupt_test - adulterated transaction.

Important Methods:<br />
  1. DHTSensor Object - <br />
     constuctor - takes in 2 values. (String ipaddress, flaot frequencyband)<br />
    .Sense(float temperature, float humidity) - This method is used to sense th3e values of temperature and humidity passed in as a parameter. Takes two parameters. <br />
    .GetTemp() - Gets the temperature of the sensor's recorded value.<br />
    .GetHumdity() - Gets the humidity of the sensor's recorded value.<br />
  
  2. BlockchainNode Object i.e nodeList[] - <br />
    .StartBlockchain() - Initiates the Blockchain Object on that particular object of BlockchainNode.<br />
    .sendTransaction(Transaction t, time_t sTime, int closeNodeCount) - recieves transaction "t" from the sensor at time "sTime" and tells that closeNodeCount-1 other nodes got it too.<br />
    .bChain.DisplayBlockchain() - Prints out the Blockchain on that node.<br />
    

Now, we can test out some cases witht he above information.<br />
Considering all default values already provided, we can make 3 cases mainly for testing security.<br />

Case 1 : When three transactions to the nodes are sent and none of them are intercepted. The below should be the method calls from line 60 to 70 in "main.cpp".<br />
    		//Transmitting correct transaction to node 1.
    		nodeList[0].StartBlockchain();
		nodeList[0].sendTransaction(test,sTime,closeNodeCount);

		// Transmitting correct transaction to node 2.
		nodeList[1].StartBlockchain();
		nodeList[1].sendTransaction(test,sTime,closeNodeCount);//corrupt_test

		// Transmitting correct transaction to node 3.
		nodeList[2].StartBlockchain();
		nodeList[2].sendTransaction(test,sTime,closeNodeCount);

Case 2 : When one of the three transactions is intercepted. Here node 2 is intercepted. The below should be the method calls from line 60 to 70 in "main.cpp".<br />
    		//Transmitting correct transaction to node 1.
    		nodeList[0].StartBlockchain();
		nodeList[0].sendTransaction(test,sTime,closeNodeCount);

		// Transmitting transaction to node 2. Corrupt transaction received by node 2.
		nodeList[1].StartBlockchain();
		nodeList[1].sendTransaction(corrupt_test,sTime,closeNodeCount);//corrupt_test

		// Transmitting correct transaction to node 3.
		nodeList[2].StartBlockchain();
		nodeList[2].sendTransaction(test,sTime,closeNodeCount);
    
Case 3 : When one of the three transactions is intercepted. Here node 3 is intercepted. The below should be the method calls from line 60 to 70 in "main.cpp".<br />
    		//Transmitting correct transaction to node 1.
    		nodeList[0].StartBlockchain();
		nodeList[0].sendTransaction(test,sTime,closeNodeCount);

		//Transmitting correct transaction to node 2.
		nodeList[1].StartBlockchain();
		nodeList[1].sendTransaction(test,sTime,closeNodeCount);//corrupt_test

		// Transmitting transaction to node 3. Corrupt transaction received by node 3.
		nodeList[2].StartBlockchain();
		nodeList[2].sendTransaction(corrupt_test,sTime,closeNodeCount);
  
Case 2 and Case 3 are similar however they are NOT the same.<br /> 
These cases are shown since changing the order in which nodes recieve transactions greatly determines the sequence of the majority algorithm on that particular node.<br />
So technically there would be a new case of even Node 1 recieved a corrupt transaction.<br />

Observed Output:<br />
The displayed blockchains on each of these cases must have the same blockchains with the Hash of the correct transaction after synchronozation with external nodes too;
and the true values sent by the sensor(with default values, it would be "50.5 + 20.4"). This means that our blockchain network is Self Correcting as well as maintains Integrity.

The only FAIL Case, or a case in which the Security will be compromised is when the hacker gains a 51% majority in the transactions being transmitted to the nodes separately. 
The hacker would need to have a quantum computer or even stronger to perform these tasks as well as do the computation of mining the block by himself before the individual nodes.<br />
Hence this is not possible at the present time, so this methodology is pretty robust in this case.
This does also make the whle IOT system require high energy and power usage as well as it makes it slower. However we believe this is a trade off for security reiant IOT systems.




