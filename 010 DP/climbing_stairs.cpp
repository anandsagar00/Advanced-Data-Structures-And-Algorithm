// Video : https://youtu.be/mLfjzJsN8us?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY

// Problem Link : https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    
    int climbStairsMemo(int n,vector<int> &dp)
    {
        if(n<0)
            return 0;
        
        if(n==0)
            return 1;
        else if(dp[n]!=-1)
            return dp[n];
        else
            return dp[n]=climbStairsMemo(n-1,dp)+climbStairsMemo(n-2,dp);
    }
    
    int climbStairsTable(int n)
    {
        vector<int> dp(n+1,-1);
        
        if(n>=1)
        {
            dp[0]=1;
            dp[1]=1;
        }
        
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
        
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climbStairsTable(n);
    }
};