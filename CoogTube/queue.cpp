#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main(){
    queue<int> q;

    q.push(1);
    q.push(4);
    q.push(11);
    q.push(8);
    q.push(68);
    q.push(49);

    cout<<"Queue size: "<<q.size()<<endl;

    for(int i=0; i<6; i++){
        cout<<q.front()<<" ";
        q.pop();
    }

    if(q.empty()){ cout<<"Empty queue"<<endl;}
    else{ cout<<"Queue is not empty"<<endl;}

    return 0;
}