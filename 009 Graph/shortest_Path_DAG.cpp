// Context : https://youtu.be/ZUFQfFaU-8U?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

//Concept of edge relaxation

/*
Step 1 : Do a topo-sort , so that we get a linear ordering
*/

#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <utility>
#include <set>
using namespace std;

void topoSortDFS(vector<vector<pair<int,int> > > &arr,vector<int> &visited,stack<int> &ans,int start)
{
    visited[start]=1;
    
    for(auto &pairs:arr[start])
    {
        int neighbour_node=pairs.first;
        int neighbour_wt=pairs.second;
        if(!visited[neighbour_node])
        topoSortDFS(arr,visited,ans,neighbour_node);
    }
    ans.push(start);
}

void shortest_path(vector<vector<pair<int,int> > > &arr,stack<int> &st,vector<int> &distance,int src)
{
    //this function will calculate the shortest path starting from any given node

    distance[src]=0;

    while (!st.empty())
    {
        int node=st.top();
        st.pop();

        for(auto &neighbours:arr[node])
        {
            //this will extract all the adjacent node along with its weight
            int neighbour_node=neighbours.first;
            int neighbour_wt=neighbours.second;

            int distance_till_now=distance[node];//this will store the distance covered till now to reach node

            distance[neighbour_node]=min(distance[neighbour_node],distance_till_now+neighbour_wt);
        }
    }
}

int main()
{
    int n;
    cin>>n;

    //This is a weighted Directed-Acyclic-Graph , so we will have to store the edge weight as well
    vector<vector<pair<int,int> > > arr(n);

    int edges;
    cin>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v,w;//Start Edge , End edge , Edge Weight
        cin>>u>>v>>w;
        arr[u].push_back(make_pair(v,w));
    }

    int src;//this will be the source node from which we are trying to find the distance of all nodes
    // cin>>src;

    src=0; // Source is always 0 in GFG , but you can remove this and add your own source

    vector<int> visited(n,0);
    stack<int> st;

    //after this loop finishes I'll have Topological Sorting of the graph ,
    //Which will give me linear ordering and will make things easy for us
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            topoSortDFS(arr,visited,st,i);
        }
    }

    int infinity=99999; // This is a fairly large value which can be treated as infinity
    vector<int> distance(n,infinity);
    shortest_path(arr,st,distance,src);

    for(auto &it:distance)
    cout<<it<<" ";
}