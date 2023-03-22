//Sum of n numbers using recursion

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

int sum(int n)
{
    if(n==0)
    return 0;
    else
    {
        return n + sum(n-1);
    }
}

int main()
{
    cout<<sum(100);
}