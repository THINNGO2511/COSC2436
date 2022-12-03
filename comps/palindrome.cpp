#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    string str, inverse_str;
    vector<char> vect1;// for str
    vector<char> vect2;// for inverse_str
    stack<char> st;
    bool approved = false;

    cin >> str;

    for(int i = 0; i < str.size(); i++){
        st.push(str[i]);
    }

    for(int i = 0; i < str.size(); i++){
        inverse_str+=st.top();
        st.pop();
    }

    int n = 0;

    for(int i = 0; i < inverse_str.size(); i++){
        if(str[i] != inverse_str[i]){
            n++;
            vect1.push_back(str[i]);
            vect2.push_back(inverse_str[i]);
        }

        if(n == 2 && vect1[0] == vect2[1]){
            approved = true;
        }
    }

    // if( n == 0){
    //     approved = true;
    // }

    if(approved){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}