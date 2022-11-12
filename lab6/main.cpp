#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

#include <iostream>
using namespace std;

class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};

int max(int a, int b);

int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

Node *insertNode(Node *node, int key) {
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

void printLevelOrder(Node *n, ofstream &out){
    if(n == nullptr){
        return;
    }
    queue<Node*> q;
    q.push(n);
    while(!q.empty()){
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++){
            Node *cu = q.front();
            q.pop();
            out<<cu->key<<" ";
            if(cu->left != nullptr){
                q.push(cu->left);
            }
            if(cu->right != nullptr){
                q.push(cu->right);
            }
        }
    }
}

int main(int argc, char** argv){
    int size, num;
    vector<int> list;

    // ifstream in("input3.txt");
    // ofstream out("output1.txt");

    ArgumentManager am(argc, argv);
    ifstream in(am.get("input"));
    ofstream out(am.get("output"));

    in>>size;
    Node *root=NULL;

    while(in>> num){
        list.push_back(num);
    }

    for(int i=0; i<list.size(); i++){
        root = insertNode(root, list[i]);
    }
    printLevelOrder(root, out);

    return 0;
}