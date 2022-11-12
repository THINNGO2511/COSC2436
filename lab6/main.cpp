#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char** argv){
    int size, num;
    vector<int> list;

    ifstream in("input1.txt");
    ofstream out("output1.txt");

    in>>size;

    while(in>> num){
        list.push_back(num);
    }

    for(int i=0; i<list.size(); i++){
        cout<<list[i]<<endl;
    }


    return 0;
}