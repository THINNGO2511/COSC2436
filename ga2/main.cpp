#include "ArgumentManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

// int main(int argc, char *argv[])
// {
// ArgumentManager am(argc, argv);
// ifstream input(am.get("input"));
// ofstream output(am.get("output"));

bool redundantBrackets(string e) {
    stack<char> s;
    for (int i = 0; i < e.length(); i++) {
        if (!(e[i] == ')' || e[i] == '}' || e[i] == ']')) {
            s.push(e[i]);
        }
        else {
            if (s.top() == '(' || s.top() == '{' ||  s.top() == '[') {
                return true;
            }
            while (!(s.top() == '(' || s.top() == '{' || s.top() == '[')) {
                s.pop();
            }
            s.pop();
      }
  }
  return false;
}

bool checkBracketsPresence(string e) {
    for(int i = 0; i <e.size(); i++){
        if(e[i] == ')' || e[i] == '}' || e[i] == ']' || e[i] == '(' || e[i] == '{' || e[i] == '[' ){
            return true;
        }
    }
    return false;
}

string convertStringtoBrackets(string e){
    string result;
    for(int i=0; i < e.length(); i++){
        if(e[i] == ')' || e[i] == '}' || e[i] == ']' || e[i] == '(' || e[i] == '{' || e[i] == '[' ){
            result+=e[i];
        }
    }
    return result;
}


bool parenthesesCheck(string str){
    stack<char> s;
    char x;

    for(int i=0; i<str.size(); i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s.push(str[i]);
            continue;
        }
        if (s.empty() && checkBracketsPresence(str)){
            return false;
        }
        switch (str[i]) {
        case ')':
            x = s.top();
            s.pop();
            if (x=='{' || x=='['){
                return false;
            }
            break;
        case '}':
            x = s.top();
            s.pop();
            if (x=='(' || x=='['){
                return false;
            }
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x =='(' || x == '{'){
                return false;
            }
            break;
        }
    }
    return (s.empty());
}


int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
 
    stack<char> st; 
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
        }
        else if (c == '(' || c == '[' || c == '{'){
            st.push(c);
        }
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (c == '}') {
            while (st.top() != '{') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (c == ']') {
            while (st.top() != '[') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
 
}

int evaluatePostfixExpression(string expression) {
    stack<int> st;
    for (int i = 0; i < expression.length(); i++){
        char c = expression[i];
        if (c >= '0' && c <= '9'){
            int temp = (int)(c - '0');
            st.push(temp);
        }
        else{
            int op1 = st.top();
            st.pop(); 
            int op2 = st.top();
            st.pop();
            switch(c){
                case '+':
                    st.push(op2 + op1);
                    break;
                case '-':
                    st.push(op2 - op1);
                    break;
                case '*':
                    st.push(op2 * op1);
                    break;    
                case '/':
                    st.push(op2 / op1);
                    break;
            }
        }
    }
    return st.top();
}

int main(int argc, char *argv[])
{
    string str;
    vector<string> vect;

    // ifstream in("input1.txt");
    // ofstream out("output1.txt");

    ArgumentManager am(argc, argv);
    ifstream in(am.get("input"));
    ofstream out(am.get("output"));
    
    while(getline(in,str)){
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        if(parenthesesCheck(convertStringtoBrackets(str)) && !redundantBrackets(str) && str.size()>0){
            vect.push_back(str);
        }
    }

    if(vect.size()==0){
        out<<"No Valid Expression"<<endl;
    }

    priority_queue<pair<int, string> > q;

    for(int i=0; i<vect.size(); i++){
        string s=vect[i];
        int num = evaluatePostfixExpression(infixToPostfix(s));
        q.push(make_pair(num, s));
    }

    vector<string> listResult;

    while(!q.empty()){
        listResult.push_back(q.top().second);
        q.pop();
    }

    reverse(listResult.begin(), listResult.end());

    for(int i= 0; i<listResult.size(); i++){
        out<<listResult[i]<<endl;
    }

}