//Context : https://youtu.be/AxNNVECce8c?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// Print all sub-sequences of a string

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<unordered_map>
#include<set>
#include<map>
#include<unordered_set>
#include<string>
#include<limits.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;

void printSub(string &str,int i,string temp)
{
    if(i>=str.size())
    {
        cout<<temp<<"\n";
    }
    else
    {
        //there can be two cases CASE 1 : take the letter at i in subseq , CASE 2 : don't

        //Case 1
        printSub(str,i+1,temp+str[i]);

        //Case 2
        printSub(str,i+1,temp);
    }
}

int main()
{
    string str="1234";
    printSub(str,0,"");
}