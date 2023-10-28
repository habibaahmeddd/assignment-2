//file:A2_S21_20220102_problem1.cpp
//purpose:solving problem number 1
//author:habiba ahmed yousef
//ID:20220102
//TA:rana abdelhakim
//date:25 oct 2023 

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

void eraseExcessiveWhitespaces(char* arr) {
    string str(arr);  // Convert character array to string

    // Use stringstream to remove excessive whitespaces
    stringstream ss;
    ss << str;

    str.clear();  // Clear the string

    string word;
    while (ss >> word) {
        str += word + " ";  // Reconstruct the string with a single space between words
    }

    // Remove trailing whitespace
    if (!str.empty() && str.back() == ' ') {
        str.pop_back();
    }

    // Copy the modified string back to the character array
    strcpy(arr, str.c_str());
}

int main() {
    char arr[100];
    cin.get(arr, 100);
    eraseExcessiveWhitespaces(arr);
    char c = arr[0];
    putchar(toupper(c));
    for (int x = 1; x < strlen(arr); x++) {
        putchar(tolower(arr[x]));
    }



    return 0;
}
