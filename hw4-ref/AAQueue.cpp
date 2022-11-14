#include <iostream>
#include "AAQueue.h"
#include "AAqueueNode.h"
#include <string>
using namespace std;

Queue::Queue(): head(nullptr), tail(nullptr), size(0)
{} //queue constructor

Queue::~Queue() //destructor
{
  qNode* curr;
  while(head != nullptr)
  {
    curr = head;
    head= curr->next;
    delete curr;
  }
  tail = nullptr;
  size=0;
}

void Queue::enqueue(string line)
{
  qNode* newqNode = new qNode(line); //create a new queue node
  if(head == nullptr)  // if is empty queue, head= tail = newNode, then set and return 
  {
    head = newqNode;
    tail = newqNode;
    size++;
    return;// this return is important!!!
  }
  tail->next = newqNode;   // if not empty, append it to the end of the queue
  tail = newqNode;
  size++;
}

void Queue::dequeue()
{
  if(isEmpty())
     return;

    qNode* tempNode= head;
    head= head->next;
    delete tempNode;
    tempNode = nullptr;
    size--;

    if(head==nullptr) //if we deleted the last element in the queue, set tail to null
    tail = nullptr;
  }

string Queue:: peek()
{
  if(isEmpty())
  {
    return "empty queue";
  }
  cout<<head->cmd<<'\n';
  return head->cmd;
}
bool Queue::isEmpty()
{
  if(head==nullptr)
  return true;
  else
  return false;
}
