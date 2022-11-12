#include "ArgumentManager.h"
#include "linkedStack.h"
#include "linkedlist.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

nodeType<string> *getDup(nodeType<string> *b1, nodeType<string> *b2) {
  if (b1 == NULL || b2 == NULL)
    return NULL;

  if (stoll(b1->value) < stoll(b2->value))
    return getDup(b1->link, b2);

  if (stoll(b1->value) > stoll(b2->value))
    return getDup(b1, b2->link);

  nodeType<string> *temp = (nodeType<string> *)malloc(sizeof(nodeType<string>));
  temp->value = b1->value;

  temp->link = getDup(b1->link, b2->link);
  return temp;
}

void swap(nodeType<string>** head_ref, nodeType<string>* cuX, nodeType<string>* cuY, nodeType<string>* prevY){
  *head_ref = cuY;
  prevY->link = cuX;

  nodeType<string> *temp = cuY->link;
  cuY->link=cuX->link;
  cuX->link = temp;
}

nodeType<string> *sort(nodeType<string>* cu){
  if(cu==NULL){
    return NULL;
  }
  if(cu->link == NULL){
    return cu;
  }

  nodeType<string> *min=cu;
  nodeType<string> *beforeMin;
  nodeType<string> *ptr;

  for(ptr=cu; ptr->link !=NULL; ptr = ptr->link){
    if(stoll(ptr->link->value) < stoll(min->value)){
      min = ptr->link;
      beforeMin = ptr;
    }
  }

  if(min != cu){
    swap(&cu, cu, min, beforeMin);
  }

  cu->link = sort(cu->link);

  return cu;
}

nodeType<string> *sortMerge(nodeType<string>* a, nodeType<string> *b){
  nodeType<string> *temp=NULL;

  if(a == NULL){
    return (b);
  }else if (b == NULL){
    return (a);
  }
  if(stoll(a->value) <= stoll(b->value)){
    temp = a;
    temp->link = sortMerge(a->link, b);
  }else{
    temp = b;
    temp->link = sortMerge(a, b->link);
  }
  return (temp);
}

nodeType<string> *removeDuplicate(nodeType<string>* cu){
  if(cu == NULL){
    return NULL;
  }

  cu->link = removeDuplicate(cu->link);

  if(cu->link != NULL && stoll(cu->link->value) == stoll(cu->value)){
    nodeType<string> *temp = cu->link->link;
    delete cu;
    delete cu->link;
    return temp;
  }
  return cu;
}

//this doesn't work on case 3
// void print(nodeType<string> *cu, ofstream &out){
//   if(cu == NULL){
//     out<<"";
//     return;
//   }
//   out<< stoll(cu->value)<<endl;
//   print(cu->link, out);
// }

//somehow this doesn't work either
// nodeType<string> *insertNode(nodeType<string> *cu, string value){
//   if(cu == NULL){
//     nodeType<string> *newNode;
//     newNode->value = value;
//     return newNode;
//   }else{
//     cu->link = insertNode(cu->link, value);
//   }
//   return cu;
// }

int main(int argc, char **argv) {

  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ifstream command(am.get("command"));
  ofstream out(am.get("output"));

  // ifstream input("input13.txt");
  // ofstream out("output1.txt");

  linkedList<string> bar1;
  linkedList<string> bar2;

  string toAdd;         //
  string whichBar = ""; // should hold only Bar1 or Bar2

  while (getline(input, toAdd)) {
    toAdd.erase(remove(toAdd.begin(), toAdd.end(), '\n'), toAdd.end());
    toAdd.erase(remove(toAdd.begin(), toAdd.end(), '\r'), toAdd.end());
    toAdd.erase(remove(toAdd.begin(), toAdd.end(), ' '), toAdd.end());
    if (toAdd.size() > 0) {
      if (toAdd[0] == 'B') {
        whichBar = toAdd;
      } else {

        linkedStack<int> stack;
        for (int i = 0; i < toAdd.size(); i++) {

          if (toAdd[i] == '(') {
            stack.push(i);
          } else if (toAdd[i] == ')') {
            reverse(toAdd.begin() + stack.peek() + 1, toAdd.begin() + i);
            stack.pop();
          }
        }
        toAdd.erase(remove(toAdd.begin(), toAdd.end(), '('), toAdd.end());
        toAdd.erase(remove(toAdd.begin(), toAdd.end(), ')'), toAdd.end());

        if (whichBar[3] == '1') {
            bar1.insertHead(toAdd);
        } else {
            bar2.insertHead(toAdd);
        }
      }
    }
  }


  linkedList<string> innocent;
  linkedList<string> guilty;

  nodeType<string> *bar1head=bar1.head;
  nodeType<string> *bar2head=bar2.head;

  nodeType<string> *duplicates = getDup(bar1head, bar2head);
  nodeType<string> *sortedGuilty = sort(duplicates);

  nodeType<string> *combineMerge = sortMerge(bar1head, bar2head);
  nodeType<string> *generalHead = sort(combineMerge);

  guilty.head = sortedGuilty;
  innocent.head = removeDuplicate(generalHead);

  if(guilty.head != nullptr) {
    out << "Guilty:" << endl;
    guilty.print(out);
  }

  if(innocent.head != nullptr) {
    out<< "Innocent:" << endl;
    innocent.print(out);
  }
}

// need a function to handle data within parentheses; a stack would be pretty
// intuitive since it's easy to reverse
// maybe also use a stack to store parentheses