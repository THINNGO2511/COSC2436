#include "ArgumentManager.h"
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string dissect(string str){
    string small, result="";
    int n=str.length();
    vector<char> arr;

    for(int i=0;i<n; i++){
        if(str[i]== ' ' || isalpha(str[i]) || isdigit(str[i]) || str[i]=='\''){
            if(isalpha(str[i])){
                arr.push_back(tolower(str[i]));
            }else{
                arr.push_back(str[i]);
            }
        }
    }
    n=arr.size();

    for(int i=0;i<n; i++){
        result+=arr[i];
    }
    return result;
}

void printRepeatedKey(vector<string> vect, ofstream& out){
    map<string, int> M;

    for (int i = 0; i<vect.size(); i++) {
        if (M.find(vect[i]) == M.end()) {
            M[vect[i]] = 1;
        }
 
        else {
            M[vect[i]]++;
        }
    }

    for(auto it:M){
        out<< it.first << ": " << it.second <<endl;
    }
}


int main(int argc, char* argv[]){
    //there could be empty files, need an if statement for that
    // ifstream input("input1.txt");
    // ofstream output("output1.txt");

    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    string str;
    vector<string> vect;
    map<string, int> map;

    while(input>>str){
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());

        vect.push_back(dissect(str));
    }

    printRepeatedKey(vect, output);

    return 0;
}