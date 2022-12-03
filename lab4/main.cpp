#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include "ArgumentManager.h"
using namespace std;


void printQueue(priority_queue<pair<float, string> >& Queue, queue<string>& q, ofstream& out)
{
    stack<pair<float, string> >Stack;
    while (!Queue.empty()) {
        Stack.push(make_pair(Queue.top().first, Queue.top().second));
        Queue.pop();
    }
    while (!Stack.empty()) {
        q.push(Stack.top().second);
        Stack.pop();
    }

    while (!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

int main(int argc, char *argv[]) {

    // ArgumentManager am(argc, argv);
    // ifstream input(am.get("input"));
    // ofstream output(am.get("output"));

    ifstream input("input1.txt"); 
    ofstream output("output1.txt");

    string str;
    vector<string> list;
    vector<vector <string> > listLarge;

    while(getline(input, str)) {
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        list.push_back(str);
    }

    for(int i = 0; i < list.size(); i++) {
        string small;
        int n = list[i].size();
        char arr[n];
        vector<string> section;

        for(int j = 0; j < n; j++) {
            if(j==(n-1)){
                small += list[i][j];
                section.push_back(small);
            }
            else if(list[i][j]!=' '){
                small += list[i][j];
            }
            else if(list[i][j]==' '){
                section.push_back(small);
                small="";
            }
        }
        listLarge.push_back(section);
    }

    vector< vector<string> > finalList;

    for(int i = 0; i < listLarge.size(); i++) {
        string temp;
        vector<string> section;
        for(int j = 0; j < listLarge[i].size()-1; j++) {
            temp=temp+listLarge[i][j]+" ";
        }
        section.push_back(temp);
        section.push_back(listLarge[i][listLarge[i].size()-1]);
        finalList.push_back(section);
    }

    vector<float> num;
    for(int i = 0; i < finalList.size(); i++) {
        num.push_back(stof(finalList[i][1]));
    }

    priority_queue<pair<float, string > >p1;
    queue<string> q;

    for(int i = 0; i < finalList.size(); i++) {
        p1.push(make_pair(num[i], finalList[i][0]));
    }

    printQueue(p1, q, output);

    return 0;
}