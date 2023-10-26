//File:A2_S21_20220199_ProblemNum3.cpp
//Purpose:Solving problem no. 9
//Author:Abdallah Ahmed Elsayed
//ID:20220199
//TA:Rana Abdelkhalik
//Date:24 Oct 2023

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Question 9
bool bears(int n) {
    if (n == 42) {
        return true;
    } else if (n % 2 == 0 && bears(n / 2)) {
        return true;
    } else if ((n % 10) * ((n % 100) / 10) != 0 && (n % 3 == 0 || n % 4 == 0) &&
               bears(n - (n % 10) * ((n % 100) / 10))) {
        return true;
    } else if (n % 5 == 0 && bears(n - 42)) {
        return true;
    } else {
        return false;
    }
}
