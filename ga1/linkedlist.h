#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template <class Type>
struct nodeType
{
	Type value;
	nodeType<Type> *link;
};

template <class Type>
class linkedList {
public: 
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
   void reverseList();
   void destroyList();
   void print(ofstream &ofstream) const;
   //void swap(nodeType<Type> *cu, nodeType<Type> *prev);
   void swap(nodeType<Type>** head_ref, nodeType<Type>* cuX, nodeType<Type>* cuY, nodeType<Type>* prevY);
   void print() const;
   void sort(nodeType<Type> *cu);
   // bool CheckDuplicate(nodeType<Type> *a); 
   ~linkedList();
};	

//this function return length of linkedlist at the time called
template <class Type>
int linkedList<Type>::length() {
	return count;
}

//this initializes the linked list
template <class Type>
linkedList<Type>::linkedList(){
	head = NULL;
	tail = NULL;
	count = 0;
}

//insert item at tail
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

//insert item at head
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

//print data to OUTPUT FILE
template <class Type>
void linkedList<Type>::print(ofstream &ofstream) const {
    nodeType<Type> *current; //pointer to traverse the list
    current = head; //set current point to the first node
    while (current != NULL) {
        ofstream << current->value << endl;
        current = current->link;
    }
}

//this just print data to terminal
template <class Type>
void linkedList<Type>::print() const {
    nodeType<Type> *current; //pointer to traverse the list
    current = head; //set current point to the first node
    while (current != NULL) {
        cout << current->value <<endl;
        current = current->link;
    }
}

//this is the function to reverse linkedlist
template <class Type>
void linkedList<Type>::reverseList(){
  nodeType<Type> *prev=NULL;
  nodeType<Type> *temp=head;
  nodeType<Type> *nxt=NULL;

  while(temp!=NULL){
    nxt = temp->link;
    temp->link=prev;
    prev=temp;
    temp=nxt;
  }
  head=prev;
}

//destructor
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

//call for destructor
template <class Type>
linkedList<Type>::~linkedList() {
    destroyList();
}

//remove item at head
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

//remove item at head
template <class Type>
void linkedList<Type>::removeTail() {
    nodeType<Type> *temp;
    nodeType<Type> *temp2;

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

//Sorting Function
// template <class Type>
// void linkedList<Type>::swap(nodeType<Type>* cu, nodeType<Type>* prev) {
//   Type temp = cu->value;
//   cu->value = prev->value;
//   prev->value = temp;
// }

// template <class Type>
// void linkedList<Type>::sort() {
//   nodeType<Type>* cu = new nodeType<Type>();
//   nodeType<Type>* prev = new nodeType<Type>();
//   int swapped = 1;
//   while(swapped) {
//     swapped = 0;
//     cu = head->link;
//     prev = head;
//     while(cu != nullptr) {
//       if(stol(cu->value) < stol(prev->value)){
//         swap(cu , prev);
//         swapped = 1;
//       }
//       prev = cu;
//       cu = cu->link;
//     }
//   }
// }

// template <class Type>
// bool linkedList<Type>::CheckDuplicate(nodeType<Type>* a,nodeType<Type>* b)
// {
//   nodeType<Type> *temp = b;
//   while (a->head != nullptr || b->head != nullptr ){
//      if (a->value == b->value)
//             return true;
//       a = a->next;
//         b = b->next;
//     }
//  }

