// Context : https://youtu.be/uRbJ1OF9aYM?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem : https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj.
Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges.
A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph.
The answer should be sorted in ascending order.
*/

//IMP : Every node who is a part of a cycle or any node that leads to a cycle can never be a part of Safe node

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;

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

    //TODO : 

}

