#include "AAPQueue.h"
#include "AAPQueueNode.h"
#include "AAQueue.h"
#include "AAqueueNode.h"
#include "ArgumentManager.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void storeCommand(ifstream &input, Pqueue &myPQ)
 { // this function stores commands extracted from file into
					// priority queue
	string curr;
	int bkStart = 0;//bracket
	int bkEnd = 0;
	int prStart = 0;//parentheses
	int prEnd = 0;
	string command;
	string toChange;
	int priority;
	while (getline(input, curr)) {
		if (curr.find('[') != -1) 
    	{
			bkStart = curr.find('[');
			bkEnd = curr.find(']');
			prStart = curr.find('(');
			prEnd = curr.find(')');

			command = curr.substr(0, bkStart - 1);
			toChange = curr.substr(bkStart + 1, bkEnd - 1 - bkStart);
			priority = stoi(curr.substr(prStart + 1, prEnd - 1 - prStart));
			//cout << command << " " << toChange << " " << priority << " ";
			//cout << endl;
			myPQ.enPqueue(command, toChange, priority); // stores into priority queue

		}
     else if (curr.find("PRINT") != -1) // second case, becaus eprint
											 // commands have different
											 // parameters
		{
			command = "PRINT";
			prStart = curr.find('(');
			prEnd = curr.find(')');
			priority = stoi(curr.substr(prStart + 1, prEnd - 1 - prStart));
			toChange = "";
			//cout << command << " " << toChange << " " << priority << " ";
			//cout << endl;
			myPQ.enPqueue(command, toChange, priority); // stores into priority queue
		}
	}
}

void executeCmd(Pqueue &myPQ, Queue &myQ, ofstream &output) {
	while (!myPQ.isEmpty()) 
  {
		if (myPQ.peek()->cmd == "DECODE") 
    {
			myQ.enqueue(myPQ.peek()->toChange);
			cout << myPQ.peek()->cmd << endl;
		//	myPQ.dePqueue();

		}

		else if (myPQ.peek()->cmd == "REPLACE") // checked
		{
			string rawCode = myQ.peek();
			if (rawCode == "empty queue") {
				// cout <<rawCode <<endl;
			} 
      else {
				char og;
				char newChar;
				og = myPQ.peek()->toChange[0]; // extract chars to be changed
				newChar = myPQ.peek()->toChange[2];

			//	cout << myPQ.peek()->priority << " " << og << " " << newChar
				//	 << '\n';
			//	cout << rawCode.length() << endl;
				for (int i = 0; i < rawCode.length(); i++) {
					if (rawCode[i] == og) {
						rawCode[i] = newChar;
					}
				}
				myQ.dequeue();
				myQ.enqueue(rawCode);
				cout << "replaced Code: " << myQ.peek() << endl;
			}
			cout << myPQ.peek()->cmd << endl;
		//	myPQ.dePqueue();

		} 
    
    else if (myPQ.peek()->cmd == "ADD") // checked
		{
			string rawCode = myQ.peek();
			if (rawCode == "empty queue") {
				// cout <<rawCode <<endl;

			} else {
				char to = myPQ.peek()->toChange[0];
				char newchar = myPQ.peek()->toChange[2];

				cout << myPQ.peek()->priority << " " << to << " " << newchar
					 << '\n';

				string finalString = "";

				for (int i = 0; i < rawCode.length(); i++) {
					if (rawCode[i] != to) {
						finalString += rawCode[i];
					} else if (rawCode[i] == to) {
						finalString += rawCode[i];
						finalString += newchar;
					}
				}
				myQ.dequeue();
				myQ.enqueue(finalString);
				cout << "this is finalString: " << finalString << endl;
			}

			cout << myPQ.peek()->cmd << endl;
		//	myPQ.dePqueue();

		}
     else if (myPQ.peek()->cmd == "REMOVE") 
     {
			string rawCode = myQ.peek();
			if (rawCode == "empty queue") {
				// cout <<rawCode <<endl;

			} else {
				char remove = myPQ.peek()->toChange[0];
				cout << "Remove character:" << remove << endl;
				string finalString = "";
				for (int i = 0; i < rawCode.length(); i++) {
					if (rawCode[i] != remove) {
						finalString += rawCode[i];
					} else
						continue;
				}
				myQ.dequeue();
				myQ.enqueue(finalString);
				cout << "this is finalString: " << finalString;
			}
			cout << myPQ.peek()->cmd << endl;
		//	myPQ.dePqueue();

		}
     else if (myPQ.peek()->cmd == "SWAP") 
     {
			string rawCode = myQ.peek();
			if (rawCode == "empty queue") {
				// cout <<rawCode <<endl;

			} 
      else {
				char before = myPQ.peek()->toChange[0];
				char after = myPQ.peek()->toChange[2];
				// extract charsto be changed

				for (int i = 0; i < rawCode.length(); i++) {
					if (rawCode[i] == before) {
						rawCode[i] = after;
					} else if (rawCode[i] == after) {
						rawCode[i] = before;
					}
				}
				myQ.dequeue();
				myQ.enqueue(rawCode);
				cout << "swapped Code: " << myQ.peek() << endl;
			}
			cout << myPQ.peek()->cmd << endl;
			//myPQ.dePqueue();

		}

		else if (myPQ.peek()->cmd == "PRINT") 
    {
			string rawCode = myQ.peek();
			if (rawCode == "empty queue") {
				// cout <<rawCode <<endl;

			} 
      else
				output << rawCode << endl;
			myQ.dequeue();
			// cout<<myPQ.peek()->cmd<<endl;
			//myPQ.dePqueue();
		}
    myPQ.dePqueue();
	}
  
}


int main(int argc, char *argv[]) {
	ArgumentManager am(argc, argv);
	const string input = am.get("input");
	const string output = am.get("output");
	const string command = am.get("command");

	ifstream inputFile(input);
	// ifstream commandFile("command41.txt");
	ofstream outputFile(output);

	// ifstream inputFile("input41.txt");
	// // ifstream commandFile("command41.txt");
	// ofstream outputFile("output41.txt");

	Pqueue myPQ;
	storeCommand(
		inputFile, myPQ); // extract and store commands into priority queue
	Queue myQ;
	executeCmd(myPQ, myQ, outputFile);
	//string curr;

	return 0;
}




/*
int main()
{
  ifstream inputFile("input41.txt");
  Pqueue myPQ;
  storeCommand(inputFile, myPQ); //extract and store commands into priority
queue Queue myQ; executeCmd(myPQ, myQ);
  */
/*
string str1="Banna";
str1.insert(3,"a");
cout<<str1;
*/