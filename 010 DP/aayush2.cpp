#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n+2,0);

    for(int i=1;i<=n;i++)
    cin>>arr[i];

    int count=0;

    for(int i=1;i<=n;i++)
    {
        int neighbour=(arr[i-1]+arr[i+1])/2;

        if(arr[i]>neighbour)
        count++;
    }

    cout<<count<<"\n";
}