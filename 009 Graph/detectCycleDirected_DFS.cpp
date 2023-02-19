// Context : https://youtu.be/9twcmtQj4DU?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;

// Imp : If we find the same node again in current path , then it is a cycle

bool isCycle(vector<vector<int>> &arr,vector<int> &visited,vector<int> &currentPath,int start)
{
    visited[start]=1;
    currentPath[start]=1;

    for(auto neighbour:arr[start])
    {
        if(currentPath[neighbour]==1)
        return true;
        if(!visited[neighbour])
        {
            if(isCycle(arr,visited,currentPath,neighbour))
            return true;
        }
    }
    currentPath[start]=0;
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n);

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        //this is a directed graph so the edges will be uni-directional
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }

    vector<int> visited(n,0);
    vector<int> currentPath(n,0);

    bool is_cycle=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(isCycle(arr,visited,currentPath,i))
            {
                is_cycle=true;
                break;;
            }
        }
    }
    if(is_cycle)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
