#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <class T>
struct QNode{
    T data;
    QNode<T> *next;
};

template <class T>
class queue{
private:
  QNode<T>* front;
  QNode<T>* rear;

public:
  queue(){
    front = nullptr;
    rear = nullptr;
  }

  bool isEmpty(){
    return front == nullptr;
  }

  void enqueue(T _data) {
    QNode<T>* temp = new QNode<T>();
    temp->data = _data;
    temp->next = nullptr;
    if (isEmpty()){
      front = temp;
      rear = temp;
    }
    else{
      rear->next = temp;
      rear = temp;
    }
  }

  void dequeue(){
    if (!isEmpty()){
      QNode<T>* temp = front;
      front = front->next;
      delete temp;
    }
  }

  QNode<T>* getFront(){
    if (!isEmpty())
      return front;
    return nullptr;
  }
};

#endif