#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
struct Node { 

  T val;
  Node<T>* next;

} ; 

template<typename T>
class linkedStack { 

  private:
    Node<T>* head;
  public:
    linkedStack() { head = nullptr; }
    ~linkedStack() { 

      while(head != nullptr) {

        Node<T>* temp = head;
        head=head->next;
        delete temp;
        
      }
      
    }
    bool isEmpty() { return head==nullptr; }
    bool push(int i) { 

      Node<T>* temp = new Node<T>;
      temp->val = i;
      temp->next = nullptr;

      if(isEmpty()) { 

        head = temp;
          
      } else {

        temp->next = head;
        head = temp;
        
      }
      
      return true;
      
    }
    bool pop() {

      if(isEmpty()) { return false; }
      else { 

        Node<T>* temp = head;
        head=head->next;
        delete temp;
        return true;
        
      }
      
    }
    T peek() { 

      if(isEmpty()) { return NULL; }
      else { return head->val; }
      
    }
    void print() {

      while(!isEmpty()) { cout << peek() << endl; pop(); }
      //cout << endl;
      
    }

} ; 