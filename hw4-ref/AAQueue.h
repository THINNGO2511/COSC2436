#ifndef QUEUE_H
#define QUEUE_H
#include "AAqueueNode.h"
#include <string>
using namespace std;

class Queue
{
  private:
    qNode* head;
    qNode* tail;
    int size;

  public:
    Queue();
    ~Queue();
    void enqueue(string);
    void dequeue();
    string peek();
    bool isEmpty();

};

#endif