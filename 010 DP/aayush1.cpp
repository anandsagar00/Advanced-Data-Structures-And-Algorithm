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


int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    cin>>arr[i];

    if(k==1)
    {
        cout<<"1\n";
    }
    else
    {
        int min_val=INT_MAX;
        for(int i=0;i<=n-k;i++)
        {
            int val=arr[i];
            int flag=0;
            for(int j=i+1;j<i+k;j++)
            {
                if(abs(arr[j-1]-arr[j])!=1)
                {
                    flag=1;
                    break;
                }
                val=arr[j];
            }
            if(!flag)
            min_val=min(min_val,val-1);
        }
        cout<<min_val<<"\n";
    }

}