//Sum of n numbers using recursion

#include<iostream>
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