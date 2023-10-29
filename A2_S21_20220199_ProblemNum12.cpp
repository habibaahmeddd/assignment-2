//File:A2_S21_20220199_ProblemNum12.cpp
//Purpose:Solving problem no. 12
//Author:Abdallah Ahmed Elsayed
//ID:20220199
//TA:Rana Abdelkhalik
//Date:24 Oct 2023

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string toLowercase(const string& str) {
    string lcString = str;
    for (char& lc : lcString) {
        lc = tolower(lc);
    }
    return lcString;
}

int main() {

    map<string, int> Phishing_Keyords = {
            {"survey",                                                         3},
            {"cone ring",                                                      3},
            {"password",                                                       2},
            {"social security number",                                         3},
            {"account",                                                        4},
            {"email",                                                          3},
            {"link",                                                           3},
            {"update",                                                         6},
            {"payment",                                                        2},
            {"information",                                                    4},
            {"winner",                                                         2},
            {"venmo",                                                          3},
            {"verify",                                                         2},
            {"confirm here",                                                   7},
            {"limited time offer",                                             3},
            {"medical information",                                            5},
            {"survey",                                                         3},
            {"cone ring",                                                      3},
            {"paypal",                                                         2},
            {"card pin",                                                       4},
            {"citybank",                                                       3},
            {"mc fee",                                                         2},
            {"pricey electronics ",                                            2},
            {"free donuts",                                                    3},
            {"rewards",                                                        3},
            {"un usual login activity",                                        5},
            {"login credit details",                                           2},
            {"please take care of this right away so you can use your domain", 1},
            {"alert",                                                          3},
            {"request",                                                        3},
            {"atm",                                                            2},
            {"financial institution",                                          3},
    };


    string Name_Of_File = "C:\\Users\\iRepair\\Downloads\\semster1,2\\oop\\phishing\\ll.txt";

    ifstream file(Name_Of_File);
    if (!file.is_open()) {
        cout << "Failed to open file: " << Name_Of_File << std::endl;
        return 1;
    }

    map<string, int> Occurrences_Keyword;
    int TotalPoints = 0;

    string line_by_line;
    while (getline(file, line_by_line)) {

        string lowercaseLine = toLowercase(line_by_line);

        for (const auto &entry: Phishing_Keyords) {
            const string &keyword = entry.first;
            int Value = entry.second;

            size_t position = lowercaseLine.find(keyword);
            while (position != string::npos) {
                Occurrences_Keyword[keyword]++;
                TotalPoints += Value;
                position = lowercaseLine.find(keyword, position + keyword.length());
            }
        }
    }

    file.close();

    for (const auto &entry: Occurrences_Keyword) {
        const string &keyword = entry.first;
        int occurrences = entry.second;
        int pointTotal = occurrences * Phishing_Keyords[keyword];

        cout << "Keyword: " << keyword << endl;
        cout << "Occurrences: " << occurrences << endl;
        cout << "Point Total: " << pointTotal << endl;
        cout << endl;
    }

    cout << "Total Points: " << TotalPoints << endl;

    return 0;
}
