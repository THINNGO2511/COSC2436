#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H
#include <iostream>
using namespace std;

template <class T>
struct PNode {
    T data;
    T toChange;
    int prio;
    PNode<T> *next;
};

template <class T>
class prio_queue {
private:
    PNode<T> *front;
    PNode<T> *rear;

public:
    prio_queue(){
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(T _data, T _toChange, int _prio) {
        PNode<T> *temp = new PNode<T>();
        temp->data = _data;
        temp->toChange = _toChange;
        temp->prio = _prio;
        temp->next = nullptr;

        if (isEmpty()) {
            front = temp;
            rear = temp;
        }

        else {
            PNode<T> *cu = front;
            PNode<T> *prev = nullptr;
            if (temp->prio < cu->prio) {
                temp->next = front;
                front = temp;
            }
            else {
                while (cu != nullptr && temp->prio >= cu->prio) {
                    prev = cu;
                    cu = cu->next;
                }
                prev->next = temp;
                temp->next = cu;
                if (temp->next == nullptr)
                    rear = temp;
            }
        }
    }

    void dequeue(){
        if (!isEmpty()) {
            PNode<T> *temp = front;
            front = front->next;
            delete temp;
        }
    }

    PNode<T>* getFront() {
        if (!isEmpty())
            return front;
        return nullptr;
    }

    void print() {
        PNode<T> *cu = front;
        while (cu != nullptr) {
            cout<< cu->prio<<" "<< cu->data<<" "<<cu->toChange<< endl;
            cu = cu->next;
        }
    }
};

#endif