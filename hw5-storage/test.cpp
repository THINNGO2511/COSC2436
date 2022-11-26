// C++ program for B-Tree insertion
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include "ArgumentManager.h"
#include <queue>
#include <stack>
using namespace std;

int analyze_command(string cmd){// return degree
    string result;

    result = cmd.substr(cmd.find("=")+1);

    return stoi(result);
}

int analyze_level(string level){// return level
    string result;

    result = level.substr(level.find(" ")+1);

    return stoi(result);
}

struct node
{
    int *key; // An array of keys
    node **child; // Minimum degree (defines the range for number of keys)
    bool leaf; // An array of child pointers
    int n; // Current number of keys
    node(int deg)
    {
        key = new int[deg];
        leaf = true;
        child=new node*[deg+1];
        n = 0;
        for(int i=0;i<deg;i++){
            child[i]=NULL;
        }
    }
    node* findNode(int data, node*temp,int t,node* root);
    void splitChild(node*temp,int t);
    void fullCheck(node*temp,int t);
    void printLevel(node*temp,int level,ofstream& fout);
    void height(node*temp,int height,int& result);
};

class btree{
    private:
        node* root;
        int t;

    public:
        btree(int val){
            root=NULL;
            t=val;
        }
        
        node* getRoot(){
            return root;
        }
        
        void insert(int data){
            if(root==NULL){
                root=new node(t);
                root->leaf=true;
                root->key[0]=data;
                root->n=1;
            }
            else{
                root= root->findNode(data, root,t,root);
                // root->fullCheck(root,t);
            }
        }

        void printLevel(int level,ofstream &fout){
            root->printLevel(root,level,fout);
        }
        
        bool isSearched(int data, int degreeNum){
            for(int i=0 ; i<degreeNum-1 ; i++){
                cout<<root->findNode(data,root, degreeNum, root)->key[i]<<endl;
                if(data == root->findNode(data,root, degreeNum, root)->key[i]){
                // root->findNode(data,root, degreeNum, root);
                    return true;
                }
            }
            return false;
        }

        int height(){
            int result;
            root->height(root,1,result);
            return result;
        }

};

    node* node::findNode(int data, node* node_active,int t,node*temp){

        if(leaf){
            int i=t;
            /// go through keys until the value before it isnt null///
            while(!key[i-1]){
                i--;
            }
            //// if value before key is greater than the data push it to the right///
            while(key[i-1]>data && i!=0){
                key[i]=key[i-1];
                i--;
            }
            //// insert the value in the respective place in the node////
            key[i]=data;
            n=n+1;
        }

        else{
            ///// If the node is not leaf go to its appropriate child ////
             int i=0;
            while(i<n && data>key[i] ){
                i++;
            }
            child[i]->findNode(data,this,t,temp);
            //node_active->child[i]->findNode(data,node_active,t,temp);
        }
        ////// After insertion if the node is full then split it/////
        if(n==t){
        ///// If it is a root make the root the child of a new node then split the new node child///
            if(this==temp){
                node*s=new node(t);
                s->leaf=false;
                s->child[0]=this;
                s->splitChild(this,t);
                return s;

            }
            else{
                ///// split the child of this parent /////.
               node_active->splitChild(this,t);
            }
        }
        return temp;
    }


    void node::splitChild(node*fullNode, int t){
        node*rightNode=new node(t);
        int i_right=0,move_up=(t-1)/2;
        //// The nunmber of keys in th4e node at first entry//
        int n_fullNode=fullNode->n;
        int carry=fullNode->key[move_up],i_child=0;
        float val1 = ceil(float(t)/2);
         int walk_child=val1;
        for(int i= move_up+1; i<n_fullNode; i++){
            rightNode->key[i_right]=fullNode->key[i];
            i_right++;
            //fullNode->key[i]=NULL;
            fullNode->n=(fullNode->n)-1;
            rightNode->n=(rightNode->n)+1;
        }
        if(fullNode->leaf==false){
            for(int a=walk_child;a<=t;a++){
            rightNode->child[i_child]=fullNode->child[a];
            i_child++;
        }
        rightNode->leaf=fullNode->leaf;
        }
        int hold=t-1;
        while(child[hold]!=fullNode){
           child[hold+1]=child[hold];
            hold--;
        }
        child[hold+1]=rightNode;
        int j=t-1;
            while(!key[j-1] && j!=0){
                j--;
            }
            //// if value before key is greater than the data push it to the right///
            while(key[j-1]>carry && j!=0){
                key[j]=key[j-1];
                j--;
            }
            //// insert the value in the respective place in the node////
            key[j]=carry;
            n=n+1;
            fullNode->n=(fullNode->n)-1;
    }

    void node::printLevel(node*temp,int level,ofstream &fout){
        if(level>1 && leaf){
            return;
        }
        else if(level==1){
            for(int i=0;i<n;i++){
				cout<<key[i]<<" ";
            }
        }
        else{
            // for(int i=0;i<=n;i++){
            for(int i=0;i<n;i++){
                child[i]->printLevel(temp,level-1,fout);
            }
        }

    }
        
    void node:: height(node*temp, int h,int& result){
        if(leaf){
            result=h;
            return;            
        }
        child[0]->height(temp,h+1,result);
    }


// Driver program to test above functions
int main()
{
    ifstream input("input1.txt");
    ifstream command("command1.txt");
    ofstream output("output1.txt");

    int n;
    string cmd, level;
    int degree, levelNum;
    vector<int> numVect, levelVect;

    // getting input
    while(input>>n){
        numVect.push_back(n);
    }

    //getting command
    command >> cmd;
    command.ignore();
    while(getline(command, level)){
        level.erase(remove(level.begin(), level.end(), '\n'), level.end());
        level.erase(remove(level.begin(), level.end(), '\r'), level.end());
        levelVect.push_back(analyze_level(level));
    }

	degree = analyze_command(cmd);

    // for(int i=0; i< levelVect.size(); i++){
    //     cout<<levelVect[i]<<endl;
    // }
	
    // for(int i = 0; i < numVect.size(); i++){
    //     cout<<numVect[i]<<" ";
    // }

	btree t1(degree);

	for(int i=0; i< numVect.size(); i++){
        cout<<numVect[i]<<" ";
		t1.insert(numVect[i]);
	}

    if(t1.isSearched(55, degree)){
        cout<<"Ladies and gentlemen, we got him"<<endl;
    }else{
        cout<<"Mission fail, we'll get 'em next time"<<endl;
    }
	// cout<<"Height="<<t1.height()<<endl;

	// for(int i= 0; i < levelVect.size(); i++){
	// 	if(levelVect[i] > t1.height()){
	// 		cout<<"Empty"<<endl;
	// 	}
	// 	else{
	// 		t1.printLevel(levelVect[i], output);
    //         cout<<endl;
	// 	}
	// }

	return 0;


}