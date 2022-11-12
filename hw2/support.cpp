#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

string decode(string str){//decode from a string of list, decode it then return a new one
    string result="", small="";//result as final product, small as elements contain by vector section
    int n=str.length();// integer n to get string length
    char arr[n];// turn string into an array of char
    vector<string> section;//to contain and divide sections of the string

    for(int i=0;i<n;i++){
        arr[i]=str[i];//turn string into arr
    }

    for(int i=0;i<n;i++){
        if(i==(n-1)){//to ensure last id line is included due to the loop's nature
            small+=arr[i];
            section.push_back(small);
        }
        else if(arr[i]!=';'){
            small+=arr[i];//add to string;
        }
        else if(arr[i]==';'){
            section.push_back(small);
            small="";//reset small to continue with the next section of vector;
        }
    }

    //array main to collect id elements
    string line=section[section.size()-1].substr(3);
    string main[line.length()];

    for(int i=0;i<line.length();i++){
        main[i]=line[i];
    }
    
    //starting decoding sequence with replace characters and signs with corresponding numbers
    for(int i=0;i<line.length();i++){
        for(int j=0;j<section.size();j++){
            if(main[i][0]==section[j][0]){//if letter on main match starting char of smaller sections inside vector section
                //replace main[i] with the following number
                main[i].replace(0, 1, section[j].substr(2));
                //main[i]=section[j].substr(2);
                //cout<<section[j]<<endl;
            }
        }
    }
    
    //after this, must turn main arr to new string to dissect it and get position for # sign
    string newline="";

    for(int i=0; i<line.length(); i++){
        newline+=main[i];
    }

    //new main1 arr to use for this sector
    string main1[newline.length()];

    //load newline into main arr
    for(int i=0;i<newline.length();i++){
        main1[i]=newline[i];
    }

    //decode # positions
    for(int i=0; i<newline.length(); i++){
        if(main1[i]=="#"){
            main1[i]=to_string(i);
        }
    }

    //load main1 into result
    for(int i=0;i<newline.length();i++){
        result+=main1[i];
    }

    return result;
}

int main(int argc, char** argv){
    // ifstream input("input7.txt");
    // ifstream command("command7.txt");
    // ofstream out("output7.txt");

    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ifstream command(am.get("command"));
    ofstream out(am.get("output"));

    string str="";//support input to list
    vector<string> strlist;//to collect and make a list of strings

    while(getline(input,str)){//remove all whitespace both in front, behind and inside lines
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        if(str.size()>0 && str.substr(0,3)!="id:" && str.find("id:")!=string::npos){//remove empty and incomplete lines
            strlist.push_back(decode(str));
        }
    }
    
    
    string com="";
    vector<string> comlist;
    while(getline(command,com)){
        com.erase(remove(com.begin(), com.end(), '\n'), com.end());
        com.erase(remove(com.begin(), com.end(), '\r'), com.end());
        com.erase(remove(com.begin(), com.end(), ' '), com.end());
        if(com.size()>0){
            comlist.push_back(com);
        }
    }

    for(int i=0;i<strlist.size();i++){
        if(comlist.size()==0){
            out<<strlist[i]<<endl;
        }
    }

    vector<string> save; // final result
    vector<string> save1;   // temporary result with first and last commands
    // for(int i = 0; i < strlist.size(); i++) {
    //     for (int j = 0; j < comlist.size(); j++) {
    //         if (comlist[j][0] == 'l' && comlist[j].substr(comlist[j].length() - 4, 4) == strlist[i].substr(strlist[i].length() - 4, 4)) {
    //             // last filter
    //             save.push_back(strlist[i]);
    //             for (int k = 0; k < comlist.size(); k++) {
    //                 if (comlist[k][0] == 'f' && comlist[k].substr(comlist[k].length() - 4, 4) == save[i].substr(0,4)) {
    //                     save1.push_back(save[i]);
    //                 }                 
    //             }
    //             if (save1.size() > 0) {
    //                 save = save1;
    //             }
    //         }
    //         else if (comlist[j][0] == 'f' && comlist[j].substr(comlist[j].length() - 4, 4) == strlist[i].substr(0,4)) {
    //             // first filter
    //             save.push_back(strlist[i]);
    //         }
    //     }
    // }  

    for (int i=0; i<save.size(); i++){
        out<<save[i]<<endl;
    }

    return 0;
}