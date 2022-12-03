#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
using namespace std;

bool Recursion(int x, int y, int n, int m, int target, int curr, vector<vector<int> > & vect, vector<vector<bool> > pathfinder){
    if (x <0 || y<0 ||x >= n || y >= m || pathfinder[x][y]){
        return false;
    }
    curr +=vect[x][y];
    if (curr == target){
        return true;
    }
    pathfinder[x][y] = true;
    if(
        Recursion(x+1, y, n, m, target, curr, vect, pathfinder)||
        Recursion(x-1, y, n, m, target, curr, vect, pathfinder)||
        Recursion(x, y+1, n, m, target, curr, vect, pathfinder)||
        Recursion(x, y-1, n, m, target, curr, vect, pathfinder))
        return true;
    pathfinder[x][y] = false;
    return false;
}

int main(int argc, char* argv[]){
    int n, m, target; //n is row, m is column, and target is result to aim for
    int x, y; //to store i, j position for number 0
    
    
    ArgumentManager am(argc, argv);
    string infilename = am.get("input");
    string commandfilename = am.get("command");
    string outfilename = am.get("output");

    ifstream inputFile(infilename);
    ifstream commandFile(commandfilename);
    ofstream outputFile(outfilename);
    
    /*
    ifstream inputFile("input1.txt");
    ofstream outputFile("output1.txt");
    */

    //pre-emptive check for empty files
    if(inputFile.eof()){
        cout<<"Not Possiible"<<endl;
        outputFile<<"Not Possiible"<<endl;
        return 0;
    }
    
    inputFile>>n>>m;// getting row number and column number
    vector< vector<int> > vect; // creating vector 2d
    vector< vector<bool> >pathfinder(n, vector<bool>(m, false)); // creating path track to either confirm or reject cases

    int num;// to read that matrix
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < m; j++){
            inputFile>>num;
            row.push_back(num);
        }
        vect.push_back(row);
    }
    inputFile>>target;

    for(int i = 0; i < n; i++){//finding the 0 position, store it at coordinates of x and y
        for(int j = 0; j < m; j++){
            if (vect[i][j] == 0) {
                x=i;
                y=j;
            }
        }
    }
    int curr = 0;

    if(Recursion(x, y, n, m, target, curr, vect, pathfinder)){
        cout<<"Possible"<<endl;
        outputFile<<"Possible"<<endl;
    }
    else{
        cout<<"Not Possible"<<endl;
        outputFile<<"Not Possible"<<endl;
    }
    inputFile.close();
    outputFile.close();
    
    return 0;
}