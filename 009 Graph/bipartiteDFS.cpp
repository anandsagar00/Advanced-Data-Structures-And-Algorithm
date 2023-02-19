// Context : https://youtu.be/KG5YFfR0j8A?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;

bool checkBipartite(vector<vector<int>> &arr, int n, vector<int> &visited, int start, vector<int> &color)
{
    visited[start] = 1;

    if (color[start] == -1)
    {
        // if there is no any color assigned then assign a color
        color[start] = 1;
    }

    for (auto neighbour : arr[start])
    {
        if (color[neighbour] == -1)
        {
            // If the node is un-colored then assign a color which is different from curr node
            if (color[start] == 1)
                color[neighbour] = 2;
            else
                color[neighbour] = 1;
        }
        else if (color[neighbour] == color[start])
            return false;

        bool is_bip=true;
        if(!visited[neighbour])
        {
            is_bip=checkBipartite(arr,n,visited,neighbour,color);
        }
        if(!is_bip)
        return false;
    }
    return true;
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
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    bool isBipartite = true;

    /*
    IMP : Declaring color and visited array in main
    (any function which will call checkBipartite again and again) is very imp as it will check for all componets of graph
    and when you declare color array everytime in checkBipartite function it consumes a lot of time
    */
    vector<int> visited(n, 0);
    vector<int> color(n, -1); // this will stor the colors assigned to each node , -1 uncolored , 1 color1,2 color2
    // initially all nodes will be un-colored

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (!checkBipartite(arr, n, visited, i, color))
            {
                isBipartite = false;
                break;
            }
        }
    }

    if (!isBipartite)
        cout << "NO\n";
    else
        cout << "YES\n";
}
