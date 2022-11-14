#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "ArgumentManager.h"
#include "prioQueue.h"
#include "queue.h"
using namespace std;

struct Node {
  string key;
  struct Node *left, *right;
};
//initializes the BST if NULL
Node *newNode(string item) {
  struct Node *temp = new Node;
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
//insert a node
Node *insert(struct Node *node, string key) {
    if (node == NULL) return newNode(key);

    if (key.length() < node->key.length()){
        node->left = insert(node->left, key);
    }
    else if (key.length() == node->key.length()){
        node->key = key;
    }
    else{
        node->right = insert(node->right, key);
    }
    return node;
}

//Inorder printing
void printInorder(struct Node* node, ofstream &out){
    if (node == NULL) return;
    printInorder(node->left, out);
    out << node->key << endl;
    printInorder(node->right, out);
}
//Preorder printing
void printPreorder(struct Node* node, ofstream &out){
    if (node == NULL) return;
    out << node->key << endl;
    printPreorder(node->left, out);
    printPreorder(node->right, out);
}
//Postorder printing
void printPostorder(struct Node* node, ofstream &out){
    if (node == NULL) return;
    printPostorder(node->left, out);
    printPostorder(node->right, out);
    out << node->key << endl;
}

void loadCommand(prio_queue<string> &pQueue ,string &curr, string &printingOrder){// the strings must be inputted by address (&) to save the info

    int bkStart = 0;//bracket
	int bkEnd = 0;
	int prStart = 0;//parentheses
	int prEnd = 0;

	int priority;
    string command;
	string toChange;

	if (curr.find('[') != -1) {// load normal command

		bkStart = curr.find('[');
		bkEnd = curr.find(']');
		prStart = curr.find('(');
		prEnd = curr.find(')');

		command = curr.substr(0, bkStart - 1);
		toChange = curr.substr(bkStart + 1, bkEnd - 1 - bkStart);
		priority = stoi(curr.substr(prStart + 1, prEnd - 1 - prStart));
    
        pQueue.enqueue(command, toChange, priority);
	}
    
    else if(curr.substr(0, 3)=="BST"){// load BST command because of different parameters

        prStart = curr.find('(');
		prEnd = curr.find(')');

        command = "BST";
		priority = stoi(curr.substr(prStart + 1, prEnd - 1 - prStart));
		toChange = "";

        pQueue.enqueue(command, toChange, priority);
    }
    else if(curr=="Preorder" || curr == "Postorder" || curr == "Inorder"){// getting the printing order for BST
        printingOrder = curr;
    }
    
}

void runCommand(prio_queue<string> &pQueue, queue<string> queue, Node *root, string &printingOrder, ofstream &out){
    while(!pQueue.isEmpty()){

        if(pQueue.getFront()->data == "DECODE"){
            queue.enqueue(pQueue.getFront()->toChange);
        }

        else if(pQueue.getFront()->data == "REPLACE"){
            if(!queue.isEmpty()){
                string str = queue.getFront()->data;
                char OG = pQueue.getFront()->toChange[0];
                char newChar = pQueue.getFront()->toChange[2];

                for(int i = 0; i < str.length(); i++){
                    if(str[i] == OG){
                        str[i] = newChar;
                    }
                }
                queue.dequeue();
                queue.enqueue(str);
            }
        }

        else if(pQueue.getFront()->data == "ADD"){
            if(!queue.isEmpty()){
                string str = queue.getFront()->data;
                char to = pQueue.getFront()->toChange[0];
                char newChar = pQueue.getFront()->toChange[2];

                string finalString = "";

                for(int i = 0; i < str.length(); i++) {
                    if(str[i] != to){
                        finalString += str[i];
                    }else if(str[i] == to){
                        finalString += str[i];
                        finalString += newChar;
                    }
                }
                queue.dequeue();
                queue.enqueue(finalString);
            }
        }

        else if(pQueue.getFront()->data == "REMOVE"){
            if(!queue.isEmpty()){
                string str = queue.getFront()->data;
                char remove = pQueue.getFront()->toChange[0];
                string finalString = "";
                for(int i = 0; i < str.length(); i ++){
                    if(str[i] != remove){
                        finalString += str[i];
                    }else{
                        continue;
                    }
                }
                queue.dequeue();
                queue.enqueue(finalString);
            }
        }

        else if(pQueue.getFront()->data == "SWAP"){
            if(!queue.isEmpty()){
                string str = queue.getFront()->data;

                char before = pQueue.getFront()->toChange[0];
                char after = pQueue.getFront()->toChange[2];

                for(int i = 0; i < str.length(); i++){
                    if(str[i] == before){
                        str[i] = after;
                    }else if(str[i] == after){
                        str[i] = before;
                    }
                }
                queue.dequeue();
                queue.enqueue(str);
            }
        }

        else if(pQueue.getFront()->data == "BST"){
            if(!queue.isEmpty()){
                string str = queue.getFront()->data;
                root = insert(root, str);
                queue.dequeue();
            }
        }

        pQueue.dequeue();
    }

    if(printingOrder == "Inorder"){
        printInorder(root, out);
    }else if(printingOrder == "Postorder"){
        printPostorder(root, out);
    }else if(printingOrder == "Preorder"){
        printPreorder(root, out);
    }
}

int main(int argc, char **argv){
    // ifstream input("input3.txt");
    // ofstream output("output1.txt");

    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    string strCommand, strData, str, printingOrder;
    prio_queue<string> pQueue;
    queue<string> queue;
    vector<string> vect;
    struct Node *root = NULL;

    while(getline(input, str)){
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        loadCommand(pQueue, str, printingOrder);
    }

    // pQueue.print();
    // cout<<printingOrder<<endl;
    runCommand(pQueue, queue, root, printingOrder, output);// problem with reading BST lines and decode, must insert safety parameters

    // cout<<pQueue.getFront()->data<<" "<<pQueue.getFront()->toChange<<" "<<pQueue.getFront()->prio<<endl;

    return 0;
}