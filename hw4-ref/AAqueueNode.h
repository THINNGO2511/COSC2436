#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H
#include<string>
using namespace std;

struct qNode
{
  string cmd;
  qNode* next;
  qNode(string command):cmd(command), next(nullptr)
  {}
};

#endif
