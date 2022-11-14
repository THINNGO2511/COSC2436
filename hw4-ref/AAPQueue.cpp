#include "AAPQueueNode.h"
#include "AAPQueue.h"
#include <iostream>
#include <string>

using namespace std;

Pqueue::Pqueue():size(0), head(nullptr)
{}
Pqueue::~Pqueue()
{
  pqNode* curr;
  while(head!=nullptr)
  {
    curr = head;
    head= head->next;
    delete curr;
  }
  size=0;
}

pqNode* Pqueue::peek()
{
  if(isEmpty())
  {
    return nullptr;
  }
  return head;
}

bool Pqueue::isEmpty()
{
  if(head==nullptr)
    return true;

  else
    return false;
}

void Pqueue::enPqueue(string cmd, string message, int pty)
{
  pqNode* newNode = new pqNode(cmd, message, pty);

  if(isEmpty())
  {
    head= newNode;
    size++;
    return;
  }
  if(head->priority > pty) //if pty has the greatest priority, set it to head
  {
    newNode->next = head;
    head = newNode;
    size++;
  }
  else  
  {
    pqNode* curr= head;
    while(curr->next != nullptr && curr->next->priority <= pty )//curr->next == null meaning we reached the last element , curr->next->priority is checking if the one after curr will have greater or equal priority, if yes, then we keep going. if no, we stop at curr, and insert it bewteen curr and curr->next
      curr = curr->next;

      newNode->next = curr->next;
      curr->next = newNode;
      size++;
  }
}

void Pqueue::dePqueue()
{
  if(isEmpty())
  {
    return;
  }

  pqNode* tempNode = head;
  head= head->next;
  delete tempNode;
  tempNode=nullptr;
  size--;
/*
  if(head==nullptr)
    tail=nullptr;
    */
}

