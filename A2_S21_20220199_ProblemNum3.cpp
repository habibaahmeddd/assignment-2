//File:A2_S21_20220199_ProblemNum3.cpp
//Purpose:Solving problem no. 3
//Author:Abdallah Ahmed Elsayed
//ID:20220199
//TA:Rana Abdelkhalik
//Date:23 Oct 2023

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//Question 3
vector <string> split(string content , string splitter){
    vector<string> result;
    string temp="";;
    for (int i = 0; i < content.length(); ++i) {
        if(content[i]!=splitter[0]){
            temp+=content[i];
            if (i==content.length()-1){
                result.push_back(temp);
            }
        }
        else if(content[i]==splitter[0]){
            result.push_back(temp);
            temp="";
        }
    }
    for (auto it:result){
        return result;
    }
}

int main(){
    string target;
    string delimiter;
    cout<<"Select string to split: "<<endl;
    getline(cin,target);
    cout<<"Select splitter (delimiter): "<<endl;
    getline(cin,delimiter);
    vector <string> result=split(target,delimiter);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
}
