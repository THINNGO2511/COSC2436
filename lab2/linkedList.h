#include <iostream>
#include <fstream>

using namespace std;

template <class Type>
struct nodeType
{
	Type value;
	nodeType<Type> *link;
};

template <class Type>
class linkedList {
private: 
	int count;
	nodeType<Type> *head;
	nodeType<Type> *tail;
public:
   linkedList();
   int length();
   void insertTail(const Type& newItem);
   void insertHead(const Type& newItem);
   void deleteNode(const Type& deleteItem);
   void removeHead();
   void removeTail();
   void destroyList();
   void print(ofstream &ofstream) const;
   void print() const;
   ~linkedList();
};	

template <class Type>
int linkedList<Type>::length() {
	return count;
}

template <class Type>
linkedList<Type>::linkedList(){
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class Type>
void linkedList<Type>::insertTail(const Type& newItem) {
	nodeType<Type> *newNode = new nodeType<Type>();
	newNode->value = newItem;
	newNode->link = NULL;

	if (head == NULL) {
	   head = tail = newNode;
    
	} else {
	   tail->link = newNode;
	   tail = newNode;
	}
	count++;
}

template <class Type>
void linkedList<Type>::insertHead(const Type& newItem) {
    nodeType<Type> *newNode = new nodeType<Type>();
    newNode->value = newItem;
    newNode->link = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->link = head;
        head = newNode;
    }
    count++;
}

template <class Type>
void linkedList<Type>::print(ofstream &ofstream) const {
    nodeType<Type> *current; //pointer to traverse the list
    current = head; //set current point to the first node
    while (current != NULL) {
        ofstream << current->value << " ";
        current = current->link;
    }
    // out << endl;
}

template <class Type>
void linkedList<Type>::print() const {
    nodeType<Type> *current; //pointer to traverse the list
    current = head; //set current point to the first node
    while (current != NULL) {
        cout << current->value << " ";
        current = current->link;
    }
    // out << endl;
}

template <class Type>
void linkedList<Type>::destroyList() {
    nodeType<Type> *temp; //pointer to deallocate the memory occupied by the node

    while (head != NULL) {
        temp = head; //set temp to the current node
        head = head->link; //advance first to the next node
        delete temp; //deallocate the memory occupied by temp
    }
    tail = NULL; //initialize tail to NULL; head has already been set to NULL by the while loop
    count = 0;
}

template <class Type>
linkedList<Type>::~linkedList() {
    destroyList();
}

template <class Type>
void linkedList<Type>::removeHead() {
    nodeType<Type> *temp;
    temp = head;
    if (head == NULL) {
        head = NULL;
    }
    else if (head != NULL) {
        temp = head->link;
        delete head;
        head = temp;
    }
    count--;

}

template <class Type>
void linkedList<Type>::removeTail() {
    nodeType<Type> *temp;
    nodeType<Type> *temp2;

    // if (tail == NULL) {
    //     head = tail = NULL;
    // }
    // if (tail != NULL) {
    //     temp = head;
    //     while (temp->link && temp->link->link != NULL) {
    //         temp = temp->link;
    //     }
    //     temp->link = tail->link;
    //     delete tail;
    //     tail = temp;
    // }

    temp = head;
    if (temp == NULL) {
        head =  tail = NULL;
    }
    else if(temp->link==NULL) {
        head=tail = NULL;
    }
    else{
        while (temp->link!=NULL) {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        delete temp;
        tail = temp2;
        tail->link = NULL;
    }
    count--;
}