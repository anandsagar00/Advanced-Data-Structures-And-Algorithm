//Check if a given string is pallindrome using Recursion

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

bool checkPal(string str,int i)
{
    if(i>=str.size())
    return true;
    else
    {
        if(str[i]!=str[str.size()-i-1])
        return false;
        else
        return checkPal(str,i+1);
    }
}

int main()
{
    string s1="MADAM";
    string s2="hello";

    cout<<checkPal(s1,0)<<"\n";
    cout<<checkPal(s2,0)<<"\n";
    cout<<checkPal("papap",0)<<"\n";
}