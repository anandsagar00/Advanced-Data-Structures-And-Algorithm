// Context : https://youtu.be/0vVofAhAYjc?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

/*
Bellman ford algorithm is used to find shortest path in Directed graphs which can have NEGATIVE weights

This alg can also detect negative weight cycles [Cycles in graph whose weight sum is -ve]

This alg works on EDGE RELAXATION ??

EDGE RELAXATION :
Edge relaxation typically involves updating the distance or cost associated with a vertex if a new, shorter path to that vertex is found through the relaxation of an adjacent edge.
Specifically, when relaxing an edge, we compare the distance to the source vertex through the current path with the distance to the source vertex through the new path,
which is the weight of the current edge plus the distance to the adjacent vertex.
If the new path is shorter, we update the distance to the adjacent vertex with the new distance.
*/

/*
Note : We relax all the edges n-1 times , where n is the total number of nodes , we only require an edge array

Now after N-1 iterations , we perform one more iteration Nth iteration ,
now if this time the distance decreases then we have a negative weight cycle
*/

/*
In bellman ford the number of iteration are already fixed , so we don't run in INFINITE LOOP ,
if we use Dijkstra alg in case of -ve weights then everytime , the distance will update and
we will keep on inserting in queue/PQ and we will never reach end;
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INFINITY 100000000 // don't make it INT_MAX or INT_MIN as we have +ve operation as well as -ve , so will result in bit overflow

void shortestBellman(vector<vector<int> > &edges, int n, int E, int src)
{
    vector<int> distance(n, INFINITY);
    distance[src] = 0;
    // Now I will begin the process of edge relaxation n-1 time

    for (int i = 1; i <= n - 1; i++)
    {
        // relax all edges one by one

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // This is the edge relaxation step
            if (distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Now I will be doing edge relaxation one last time and if again the weight decreases then -ve wt cycle

    bool negWtCycle = false;
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (distance[u] + w < distance[v])
        {
            //since distance decreased so , -ve wt cycle
            negWtCycle=true;
            break;
        }
    }
    if(!negWtCycle)
    {
        for(auto &dist:distance)
        cout<<dist<<" ";
    }
    else
    cout<<"Negative weight cycle.\n";
}

int main()
{
    int n; // number of nodes
    cin >> n;

    int E; // number of edges
    cin>>E;
    vector<vector<int> > edges; // I will be storing U,V,W in this vector

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); // this creates a vector of size 3 by default
    }
    int src=0;//I am keeping default source as 0
    shortestBellman(edges, n, E, src);
}