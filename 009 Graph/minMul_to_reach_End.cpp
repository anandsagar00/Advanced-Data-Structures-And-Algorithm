// Context : https://youtu.be/_BvEJ3VIDWw?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int infinity=9999999;

int minimumMultiplications(vector<int>& arr, int start, int end)
{
    if(start==end)
        return 0;
    
    /*
    this will make sure that we have reached a particular number already ,
    so that we don't repeatedly process same number again and again
    */
    vector<bool> already_seen(100000,false);

    //This queue will store the number along with number of steps to reach that number
    queue<pair<int,int> > q; // {number , steps}
    q.push({start,0});
    
    already_seen[start]=true;

    while(!q.empty())
    {
        int number = q.front().first;
        int steps = q.front().second;
        q.pop();

        //Iterating over the given array to multiply

        for(auto &num:arr)
        {
            int mul=(num*1LL*number)%100000;
            if(!already_seen[mul])
            {
                //if we have not already seen the MUL then add it to queue , but first check if it is end
                if(mul==end)
                return steps+1;
                else
                {
                    already_seen[mul]=true;
                    q.push({mul,steps+1});
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
    cin>>arr[i];

    int start,end;
    cin>>start>>end;

}