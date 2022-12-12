#include <iostream>
using namespace std;

struct node{
    int data;//data
    node *next;//pointer to next node
};

class LinkedList{
    private:
        int count;//size of linked list
        node *head;//head node
        node *tail;//to tail node
    public:
        LinkedList();
        void insert(int temp);
        void print();
};

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    count = 0;
}

void LinkedList::insert(int temp){
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
    count++;
}

void LinkedList::print(){
    node *current;
    current = head;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    LinkedList list;
    list.insert(0);
    list.insert(9);
    list.insert(6);

    list.print();
    return 0;
}