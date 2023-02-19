// Context : https://youtu.be/73sneFXuTEg?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Reference : https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

// Topological sorting for Directed Acyclic Graph (DAG) is
// a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.
// Note: Topological Sorting for a graph is not possible if the graph is not a DAG.

//KAHN'S alg is a BFS approach , we will use indegree array in this alg

#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <utility>
#include <set>
using namespace std;

//IMP : the topo-sort can only be performed on DAG

/*
The nodes with indegree 0 can be placed in front as , there is no any edge coming to it , so they don't stand
behind anyone in linear ordering
*/

void BFS(vector<vector<int>> &arr,vector<int> &indegree,vector<int> &sorted)
{
    queue<int> q; // queue that will store elements with indegree 0

    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        sorted.push_back(node);

        for(auto &neighbour:arr[node])
        {
            indegree[neighbour]-=1;//decreasing the indegree of all adjacent nodes
            if(indegree[neighbour]==0)
            {
                q.push(neighbour);
            }
        }
    }
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
    vector<int> indegree(n,0);

    //this will calculate the indegree of all nodes
    //this will calculate the indegree of all nodes
    for(int i=0;i<n;i++)
    {
        for(auto &nodes:arr[i])
        indegree[nodes]++;
    }

    vector<int> ans;
    BFS(arr,indegree,ans);
}