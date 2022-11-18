#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    ifstream input("input1.txt");
    ifstream command("command2.txt");
    ofstream output("output1.txt");

    int n;
    string cmd, level;
    vector<string> levelVect;
    vector<int> numVect;

    //getting input
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
        levelVect.push_back(level);
    }

    cout<<cmd<<endl;

    for(int i=0; i< levelVect.size(); i++){
        cout<<levelVect[i]<<endl;
    }

    return 0;
}