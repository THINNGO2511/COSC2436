#ifndef PQUEUE_H
#define PQUEUE_H
#include "AAPQueueNode.h"
#include <string>
using namespace std;

class Pqueue
{
  private:
    int size;
    pqNode* head;
    
  public:
    Pqueue();
    ~Pqueue();
    pqNode* peek();
    void enPqueue(string cmd, string msg, int priority);
    void dePqueue();
    bool isEmpty();

};
#endif