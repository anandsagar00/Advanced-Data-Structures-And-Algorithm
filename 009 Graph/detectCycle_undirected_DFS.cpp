// Context : https://youtu.be/BPlrALf1LDU?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

bool isCyclePresent(vector<vector<int> > adj,vector<int> &visited,int start,int parent)
{
    visited[start]=1;
    for(auto &it:adj[start])
    {
        //If a node in adjacency list is visited and it is not current node's parent node then cycle present
        if(visited[it] && it!=parent)
        return true;
        else if(!visited[it])
        return isCyclePresent(adj,visited,it,start);
    }
    return false;
}

int main()
{
    int n;//to store number of vertices

    cin>>n;

    //This will create an empty 2d vector
    vector<vector<int> > adj(n);

    int edges;//to store the count of edges
    cin>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v;//in this I'll be store starting point and ending point of edge
        cin>>u>>v;

        //Since this is an undirected graph so we will mark twice as the same edge will be connecting both notes from both sides
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }

    vector<int> visited(n,0);//this will store the status whether the node has been visited or not

    bool isCycle=false;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            isCycle=isCyclePresent(adj,visited,i,-1);
            if(isCycle)
            break;
        }
    }
    if(!isCycle)
    cout<<"\nNo\n";
    else
    cout<<"\nYes\n";
}