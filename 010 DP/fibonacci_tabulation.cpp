// Video : https://youtu.be/tyB0ztf0DNY?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&t=478

// Find nth fibonacci number 

/*
In Tabulation we start from BASE-CASE and then we try to reach larger solution
*/

#include<iostream>
using namespace std;

int main()
{
    int n=12;
    int *dp=new int[n+1]; // create DP array in heap , which will also fill all the elements by 0
    
    if(n>=1)
    {
        dp[0]=0;
        dp[1]=1;
    }

    for(int i=2;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];

    cout<<dp[n];
    
}