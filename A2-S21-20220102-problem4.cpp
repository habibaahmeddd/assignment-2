//file:A2_S21_20220102_problem4.cpp
//purpose:solving problem number 4
//author:habiba ahmed yousef
//ID:20220102
//TA:rana abdelhakim
//date:25 oct 2023


#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

// Driver Code
int main() {
    int n;
    cin>>n;
    cout  << n << endl;
    SieveOfEratosthenes(n);
}
