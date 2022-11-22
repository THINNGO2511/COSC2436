#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

int analyze_command(string cmd){// return degree
    string result;

    result = cmd.substr(cmd.find("=")+1);

    return stoi(result);
}

int analyze_level(string level){// return level
    string result;

    result = level.substr(level.find(" ")+1);

    return stoi(result);
}

int main(int argc, char** argv){
    ifstream input("input1.txt");
    ifstream command("command2.txt");
    ofstream output("output1.txt");

    int n;
    string cmd, level;
    int degree, levelNum;
    vector<int> numVect, levelVect;

    // getting input
    while(input>>n){
        numVect.push_back(n);
    }

    for(int i = 0; i < numVect.size(); i++){
        cout<<numVect[i]<<endl;
    }

    //getting command
    command >> cmd;
    command.ignore();
    while(getline(command, level)){
        level.erase(remove(level.begin(), level.end(), '\n'), level.end());
        level.erase(remove(level.begin(), level.end(), '\r'), level.end());
        levelVect.push_back(analyze_level(level));
    }

    cout<<analyze_command(cmd)<<endl;

    for(int i=0; i< levelVect.size(); i++){
        cout<<levelVect[i]<<endl;
    }

    return 0;
}