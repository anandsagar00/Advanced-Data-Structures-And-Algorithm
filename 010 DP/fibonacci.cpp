// Video : https://youtu.be/tyB0ztf0DNY?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&t=478

// Find nth fibonacci number 

#include<iostream>
using namespace std;

int fib(int n,int dp[])
{
    if(n<=1)
    {
        dp[n]=n;
        return dp[n];
    }
    else if(dp[n]!=0)
    return dp[n];
    else
    {
        return dp[n]=fib(n-1,dp)+fib(n-2,dp);
    }
}

int main()
{
    int n=12;
    int *dp=new int[n+1]; // create DP array in heap , which will also fill all the elements by 0

    cout<<fib(n,dp);
}