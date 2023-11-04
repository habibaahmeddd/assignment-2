//file:A2_S21_20220102_problem7.cpp
//purpose:solving problem number 7
//author:habiba ahmed yousef
//ID:20220102
//TA:rana abdelhakim
//date:25 oct 2023 


#include <vector>
#include <iostream>

using namespace std;

struct dominoT
{
    int leftDots;
    int rightDots;
};

bool formsDominoChain(vector<dominoT> &dominos);

int main(int argc, char const *argv[])
{
    int n;
    vector<dominoT> dominos ;
    cout<< "How many dominos: ";
    cin>>n;
    cout<<"Enter dominos with this format for ex : 2 3 "<<endl;
    for (int i = 0; i < n; i++)
    {
        dominoT domino;
        cout<<"Enter domino "<<i+1<<" : ";
        cin>>domino.leftDots>>domino.rightDots;
        dominos.push_back(domino);
    }

    bool isChain = formsDominoChain(dominos);
    if (isChain)
    {
        cout << " Can Create Chain of dominos" << endl;
        for (int i = 0; i < dominos.size(); i++)
        {
            cout << dominos[i].leftDots << "|" << dominos[i].rightDots;
            if (i != dominos.size() - 1)
            {
                cout << " - ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Can't Create Chain of dominos" << endl;
    }

    return 0;
}

bool formsDominoChain(vector<dominoT> &dominos)
{
    bool isChain = true;

    for (int i = 0; i < dominos.size() - 1; i++)
    {
        if (dominos[i].rightDots != dominos[i + 1].leftDots)
        {
            isChain = false;
            break;
        }
    }

    if (isChain)
    {
        return isChain;
    }

    for (int i = 0; i < dominos.size(); i++)
    {

        for (int j = i; j < dominos.size(); j++)
        {
            if (dominos[i].leftDots == dominos[j].rightDots && i != j)
            {
                dominos.insert(dominos.begin() + j + 1, dominos[i]);
                dominos.erase(dominos.begin() + i);
                return formsDominoChain(dominos);
            }
        }
    }
    return isChain;
}
