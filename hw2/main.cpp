#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "linkedlist.h"
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char** argv)
{   
    ifstream inputFile("input2.txt");
    ifstream commandFile("command2.txt");
    ofstream outputFile("output2.txt");

    // ArgumentManager am(argc, argv);
    // string infilename = am.get("input");
    // string commandfilename = am.get("command");
    // string outfilename = am.get("output");

    // ifstream inputFile(infilename);
    // ifstream commandFile(commandfilename);
    // ofstream outputFile(outfilename);

    string str="";
    linkedList<string> stringlist;// THE linkedList we need
    vector<string> strlist;// a vector of strings to support loading to linked list

    while(getline(inputFile,str)){
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), ' '), str.end());

        stringlist.loadInput(str);
    }
    stringlist.sortLoad();

    string cmd="";
    
    while(getline(commandFile,cmd)){
        cmd.erase(remove(cmd.begin(), cmd.end(), '\n'), cmd.end());
        cmd.erase(remove(cmd.begin(), cmd.end(), '\r'), cmd.end());
        //cmd.erase(remove(cmd.begin(), cmd.end(), ' '), cmd.end());

        stringlist.loadCommand(cmd);
    }
    //cout<<stringlist.length()<<endl;
    stringlist.sortLoad();
    stringlist.print(outputFile);
    
}