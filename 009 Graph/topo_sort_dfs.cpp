// Context : https://youtu.be/5lZ0iJMrUMk?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Topological sorting for Directed Acyclic Graph (DAG) is
// a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.
// Note: Topological Sorting for a graph is not possible if the graph is not a DAG.

#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <utility>
#include <set>
using namespace std;

//IMP : the topo-sort can only be performed on DAG

/*
We will keep a Stack DS to store the vertices after performing DFS on that vertex
in that way we will have a linear ordering when we pop all elements of stack and store it in array or vector
*/

void DFS(vector<vector<int>> &arr,vector<int> &visited,stack<int> &st ,int start)
{
    visited[start]=1;

    for(auto &neighbour:arr[start])
    {
        if(!visited[neighbour])
        DFS(arr,visited,st,neighbour);
    }
    st.push(start);
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
    stack<int> st;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(arr,visited,st,i);
        }
    }
    
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}