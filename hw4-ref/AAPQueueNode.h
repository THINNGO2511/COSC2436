#ifndef PQ_NODE_H
#define PQ_NODE_H
#include <string>
using namespace std;

struct pqNode
{
  string cmd;
  string toChange;
  int priority;
  pqNode* next;
  pqNode(string command,string message, int pty):cmd(command),toChange(message), priority(pty), next(nullptr)
  {}
};

#endif