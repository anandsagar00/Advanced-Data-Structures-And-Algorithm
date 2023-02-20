// Context : https://youtu.be/C4gxoTaI71U?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// Note : This is a BFS problem

#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <utility>
#include <set>
using namespace std;

void BFS(vector<vector<int> > &arr,vector<int> &distance,int src)
{
    distance[src]=0;

    // in this queue I will be storing the node 
   //  along with number of steps required to reach that node starting from source node
    queue<pair<int,int> > q; 
    q.push(make_pair(src,0));

    while(!q.empty())
    {
        int node=q.front().first;
        int steps_till_now = q.front().second;
        q.pop();

        for(auto &neighbour:arr[node])
        {
            //traversing over the adjacency list of the current node
            if(steps_till_now+1<distance[neighbour])
            {
                distance[neighbour]=steps_till_now+1;
                q.push(make_pair(neighbour,distance[neighbour]));
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > arr(n);

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        //this is a undirected graph 
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int src; // this is the source node from where we have to find the shortest path
    cin>>src;

    vector<int> distance(n,99999);// filling it up with large value 
    BFS(arr,distance,src);
    
    for(auto &it:distance)
    cout<<it<<" ";
}
