#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

void decode(){

}

int main(int argc, char** argv){

    ifstream input("input1.txt");
    ifstream command("command1.txt");
    ofstream out("output1.txt");

    int n;//to be used for string size
    string str="";//support input string
    vector<char> list;//to collect and make a list of strings
    string arr[n];//to analyze and help decode strings

    getline(input,str);
    cout<<"hello"<<endl;

/*
    while(getline(input,str)){
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        cout<<str<<endl;
    }
*/

    return 0;
}