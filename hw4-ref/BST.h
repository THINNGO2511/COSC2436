#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

//setting parameters and values for BST
struct node {
  string key;
  struct node *left, *right;
};

//initializes the BST if NULL
node *newNode(string item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
//insert a node
node *insert(struct node *node, string key) {
    if (node == NULL) return newNode(key);

    if (key < node->key){
        node->left = insert(node->left, key);
    }
    else if (key == node->key){
        node->key = key;
    }
    else{
        node->right = insert(node->right, key);
    }
    return node;
}

//Inorder printing
void printInorder(struct node* node){
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}
//Preorder printing
void printPreorder(struct node* node){
    if (node == NULL) return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
//Postorder printing
void printPostorder(struct node* node){
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->key << " ";
}

#endif