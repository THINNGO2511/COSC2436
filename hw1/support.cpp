#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[]) {
  // *** You need to open files using argumentmanager when submit your assignment ***
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ifstream command(am.get("command"));
  ofstream out(am.get("output"));

  // *** Use this if you need to test each input individually, but you need to change back to using argumentmanager when you submit the assignment ***
  // ifstream input("input1.txt");
  // ifstream command("command1.txt");
  // ofstream out("output1.txt");

  string in = "";

  while(getline(input, in)) {
    // Clean up blank spaces, \n and \r, and skip blank lines
    in.erase(remove(in.begin(), in.end(), '\n'), in.end());
    in.erase(remove(in.begin(), in.end(), '\r'), in.end());
    in.erase(remove(in.begin(), in.end(), ' '), in.end());
    if(in.size() == 0)
      continue;
    
    // continue to process the input below
    
  }

  string cmd = "";

  while(getline(command, cmd)) {
    // Clean up blank spaces, \n and \r, and skip blank lines
    cmd.erase(remove(cmd.begin(), cmd.end(), '\n'), cmd.end());
    cmd.erase(remove(cmd.begin(), cmd.end(), '\r'), cmd.end());
    cmd.erase(remove(cmd.begin(), cmd.end(), ' '), cmd.end());
    if(cmd.size() == 0)
      continue;
    
    // continue to process the command below
    
  }

}