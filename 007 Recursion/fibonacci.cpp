//Return nth fibonacci using recursion

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

int fib(int n)
{
    if(n==0 || n==1)
    return n;
    else
    return fib(n-1)+fib(n-2);

}

int main()
{
    cout<<fib(19);
}