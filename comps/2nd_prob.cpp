#include <iostream>
#include <string>
#include <vector>
#include "math.h"
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void bubbleSort(vector<string> a){

    for(int i=1; i<a.size(); i++){
        for(int j=0; j<a.size()-1; j++) {
            // if(a[j].substr(0,2)>a[j+1].substr(0,2)){
            //     swap(a[j],a[j+1]);
            // }
            if(a[j]> a[j+1]){
                string temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(int argc, char** argv){
    string str="8";
    vector< vector< string > >  list;
    vector<string > vect;
    vector<string> strList;
    vector<int> numList;

    while(getline(cin,str)){
        vect.push_back(str);
        if(str=="0"){
            break;
        }
    }

    for(int i=0;i<vect.size();i++){
        if(!isalpha(vect[i][0])){
            numList.push_back(stoi(vect[i]));// a num list to contain vector size
        }
        if(isalpha(vect[i][0])){
            strList.push_back(vect[i]);// a string list
        }
    }

    queue <string> q;
    for(int i=0; i<strList.size(); i++){
        q.push(strList[i]);
    }

    for(int i=0; i<numList.size()-1; i++){
        vector<string> smallList;
        for(int j=0; j<numList[i];j++){
            smallList.push_back(q.front());
            q.pop();
        }
        list.push_back(smallList);
    }


    // for(int i=0; i<list.size(); i++){
    //     // stable_sort(list[i].begin(), list[i].end());
    //     bubbleSort(list[i]);
    // }
    bubbleSort(list[0]);

    for(int i=0; i<list.size(); i++){
        for(int j=0; j<list[i].size();j++){
            cout<<list[i][j]<<endl;
        }
        cout<<endl;
    }

    // while(!q.empty()){
    //     cout<<q.front()<<endl;
    //     q.pop();
    // }

    return 0;
}