#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "ArgumentManager.h"

int main(int argc, char *argv[]) {

  ArgumentManager am(argc, argv);

  ifstream input(am.get("input"));
  ofstream output(am.get("output"));

  // int main() {
  // ifstream input("ga3/input1.txt");
  // ofstream output("output1.txt");
 
  int num;
  BST tree;
  while (input >> num) {

    tree.insert(tree.getRoot(), num);
  }
if (! tree.empty()){

  string result = "";
  string direction = "x";
  
  tree.preOrder(tree.getRoot(), direction,result,output);

  }
    }
