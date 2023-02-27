// Context : https://youtu.be/FYrl7iz9_ZU?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
// Problem link : https://practice.geeksforgeeks.org/problems/connecting-the-graph/1

/*
You are given a graph with n vertices and m edges.

You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operation that will be required to make the graph connected.

If it is not possible to make the graph connected, return -1.
*/

// concept : Reusing the existing edge which form a cycle in one component to connect 2 components

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

// This is a Disjoint Set Data-Structure class
class DisjointSet
{
    vector<int> parent; // this will store the parent of a node
    vector<int> rank;   // this will store the rank of a given node
public:
    // Constructer to initialise the initial rank and initial parent
    DisjointSet(int n)
    {
        // using n+1 so that it can work with Graphs with node which has 1 based indexing as well
        parent.resize(n + 1);
        rank.resize(n + 1, 0); // initially the rank of all nodes will be 0

        // Initially all nodes will be parent to itself
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // This function will find the ultimate parent of a node recursively using Path Compression
    int findUltimateParent(int node)
    {
        // If the parent node of a node is node itself , then return node as it itself is the parent
        if (parent[node] == node)
            return node;
        else
        {
            // find the parent of the parent recursively and save compress the path
            return parent[node] = findUltimateParent(parent[node]);
        }
    }

    void unionByRank(int u, int v)
    {
        int ult_p_u = findUltimateParent(u);
        int ult_p_v = findUltimateParent(v);

        // If both the nodes have same ultimate parent then they are already connected
        if (ult_p_u == ult_p_v)
            return;
        else
        {
            // Connect the smaller ranked component to the larger one
            if (rank[ult_p_u] < rank[ult_p_v])
            {
                // rank will not change
                parent[ult_p_u] = ult_p_v;
            }
            else if (rank[ult_p_v] < rank[ult_p_u])
            {
                parent[ult_p_v] = ult_p_u;
            }
            else
            {
                // when both are of same rank , then we can add any one to anyone but we will have to increase rank by 1
                parent[ult_p_u] = ult_p_v;
                rank[ult_p_v]++;
            }
        }
    }

    // This function will return the total number of components till now
    // The number of unique ultimate parent will be the number of components
    int numberOfComponents()
    {
        set<int> st; // this is to store total unique elements

        // Assuming that the graph follows 0 based indexing , since array is of n+1 size so iterating from [0,n-1)

        for (int i = 0; i < parent.size()-1; i++)
            st.insert(findUltimateParent(i));

        return st.size();
    }
};

int Solve(int n, vector<vector<int>> &edge)
{
    DisjointSet DS(n);

    int extra_edges = 0; // I will be adding

    for (auto &vec : edge)
    {
        int u = vec[0], v = vec[1];

        int ulp_u = DS.findUltimateParent(u);
        int ulp_v = DS.findUltimateParent(v);

        // If parent of two nodes of an edge are same then it is a cycle
        if (ulp_u == ulp_v)
        {
            extra_edges++;
            continue;
        }
        else
        {
            DS.unionByRank(u, v);
        }
    }

    int number_of_components = DS.numberOfComponents();

    if (extra_edges >= number_of_components - 1)
        return number_of_components - 1;
    else
        return -1; // All components can't be connected
}

int main()
{
    int n; // number of nodes
    cin >> n;

    int E; // number of edges
    cin >> E;
    vector<vector<int>> edges; // I will be storing U,V,W in this vector

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v}); // this creates a vector of size 2 by default
    }
    cout << Solve(n, edges);
}