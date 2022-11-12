#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
using namespace std;



int main(int argc, char* argv[]){
    int m, n, target; //m is row, n is column, and target is result to aim for
    int x, y; //to store i, j position for number 0
    
    /*
    ArgumentManager am(argc, argv);
    string infilename = am.get("input");
    string commandfilename = am.get("command");
    string outfilename = am.get("output");

    ifstream inputFile(infilename);
    ifstream commandFile(commandfilename);
    ofstream outputFile(outfilename);
    */

    ifstream inputFile("input1.txt");
    ofstream outputFile("output1.txt");

    //pre-emptive check for empty files
    if(inputFile.eof()){
        cout<<"Not Possiible"<<endl;
        outputFile<<"Not Possiible"<<endl;
        break;
    }
    
    inputFile>>n>>m;// getting row number and column number
    int arr[n][m];// create array for matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            inputFile>>arr[i][j];
        }
    }
    inputFile>>target;

    for(int i = 0; i < n; i++){//finding the 0 position, store it at coordinates of x and y
        for(int j = 0; j < m; j++){
            if (arr[i][j] == 0) {
                x=i;
                y=j;
                cout<<x<<" "<<y<<endl;
            }
        }
    }

    if(Recursion(x, y, n, m, arr)==0){
        cout<<"Possiible"<<endl;
        outputFile<<"Possiible"<<endl;
    }
    else{
        cout<<"Not Possiible"<<endl;
        outputFile<<"Not Possiible"<<endl;
    }

    return 0;
}