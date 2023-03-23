// Video : https://youtu.be/rYkfBRtMJr8?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// Problem Link : https://practice.geeksforgeeks.org/problems/subset-sums2234/1

//The code below is my submission on GFG 

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void subsetSums(vector<int> &arr,int i,vector<int> &ans,int curr_sum)
    {
        if(i>=arr.size())
        ans.push_back(curr_sum);
        else
        {
            //We have 2 choices with each number
            
            //Choice 1 : Take the element into sum
            subsetSums(arr,i+1,ans,curr_sum+arr[i]);
            
            //Choice 2 : don't take into consideration
            subsetSums(arr,i+1,ans,curr_sum);
        }
    }

    vector<int> subsetSums(vector<int> &arr, int N)
    {
        vector<int> ans;
        subsetSums(arr,0,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends