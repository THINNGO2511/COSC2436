#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "ArgumentManager.h"
#include "linkedList.h"

using namespace std;   

int main(int argc, char* argv[]){
    string type, position;// indicate type, position (head or tail)
    
    // ifstream inputFile("input1.txt");
    // ofstream outputFile("output1.txt");

    ArgumentManager am(argc, argv);
    string infilename = am.get("input");
    string commandfilename = am.get("command");
    string outfilename = am.get("output");

    ifstream inputFile(infilename);
    ifstream commandFile(commandfilename);
    ofstream outputFile(outfilename);
    
    getline(inputFile,type);
    type.erase(remove(type.begin(), type.end(), '\n'), type.end());
    type.erase(remove(type.begin(), type.end(), '\r'), type.end());

    getline(inputFile, position);
    position.erase(remove(position.begin(), position.end(), '\n'), position.end());
    position.erase(remove(position.begin(), position.end(), '\r'), position.end());

    // inputFile.ignore();
    linkedList<string> list;
    string value;
    while (getline(inputFile, value)) {
        value.erase(remove(value.begin(), value.end(), '\n'), value.end());
        value.erase(remove(value.begin(), value.end(), '\r'), value.end());
        value.erase(remove(value.begin(), value.end(), ' '), value.end());

        if (position == "head") {
            if (value != "removetail" && value != "removehead") {
                list.insertHead(value);
            }
            if (value == "removetail") {
                list.removeTail();
            }
            if (value == "removehead"){
                list.removeHead();
            }
        }
        else if (position == "tail") {
            if (value != "removetail" && value != "removehead") {
                list.insertTail(value);
            }
            if (value == "removetail" && value != "remove tail"){
                list.removeTail();
            }
            if (value == "removehead" && value != "remove head"){
                list.removeHead();
            }  
        }
    }
    inputFile.close();
    list.print(outputFile);

    return 0;
}