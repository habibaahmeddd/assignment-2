//File:A2_S21_20220199_ProblemNum3.cpp
//Purpose:Solving problem no. 3
//Author:Abdallah Ahmed Elsayed
//ID:20220199
//TA:Rana Abdelkhalik
//Date:23 Oct 2023

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Question 6-a:
vector<int> result;

void printBinary(int n) {
    if (n != 1) {
        if (n % 2 == 0) {
            result.push_back(0);
        } else if (n % 2 != 0) {
            result.push_back(1);
        }
        int x = n / 2;
        printBinary(x);
    } else {
        result.push_back(1);
    };
}


//Question 6-b:
void numbers(string prefix, int k) {
    string constantPrefix=prefix;
    for (int i = 0; i < pow(2, k); ++i) {
        int tmp=i;
        for (int j = 0; j < k; ++j) {
            if (tmp % 2 == 0) {
                prefix += to_string(0);
            }
            else if (tmp % 2 != 0) {
                prefix += to_string(1);
            }
            else if (tmp == 0) {
                prefix += to_string(0);
            }
            tmp/=2;
        }
        cout<<prefix<<endl;
        prefix=constantPrefix;
    }
}

