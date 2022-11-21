#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;
};
node *newNode(int data) {
  node *temp = new node();

  temp->data = data;
  temp->left = temp->right = NULL;

  return temp;
}

class BST {
private:
  node *root;

public:
  BST() { root = nullptr; }
  ~BST();

  node *getRoot() { return root; }
  node *insert(node *, int);
  bool empty() { return root == nullptr; }
  void preOrder(node *, string, string, ofstream & output);
};
BST ::~BST() {
  if (root != nullptr) {
    while (root->left != nullptr || root->right != nullptr) {
      node *temp = root;
      root = root->left;
      delete root;
      root = root->right;
      delete root;
    }
    delete root;
  }
}
node *BST::insert(node *cu, int d) {
  if (cu == nullptr) {
    node *temp = newNode(d);

    if ( root== nullptr) {
      root = temp;
      return root;
    }

    else
      return temp;
  }

  else if (d > cu->data) {
    cu->right = insert(cu->right, d);
  }

  else if (d < cu->data) {
    cu->left = insert(cu->left, d);
  }

  else {
    cu->data = d;
  }

  return cu;
}
void BST ::preOrder(node *cu, string d, string f, ofstream &output) {
  if (cu == nullptr)
    return;
  f += d;
  
 output << "[" << f << "] " << cu -> data << endl;

 
  preOrder(cu -> left, "l", f, output);

 
  preOrder(cu->right,"r", f, output);
}
