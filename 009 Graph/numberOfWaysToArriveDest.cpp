// Context : https://youtu.be/_-0mx0SmYxA?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int infinity=9999999;

int countPaths(vector<vector<pair<int,int> > > &arr)
{
    //The default src and dest nodes are 0 and n-1
    int n=arr.size();
    int src=0,dest=n-1;

    //I will also use a ways vector which will store the total number of ways to reach a particular node using shortest path
    vector<int> ways(n,0);

    vector<int> distance(n,infinity);
    distance[src]=0;
    ways[src]=1;

    priority_queue<vector<int> , vector<vector<int>> ,greater<vector<int>>> pq;

    pq.push({0,0});

    while(!pq.empty())
    {
        int node=pq.top()[1];
        int distance_till_now=pq.top()[0];
        pq.pop();

        for(auto &neighbours:arr[node])
        {
            int neighbour=neighbours.first;
            int neighbour_wt=neighbours.second;

            if(distance_till_now+neighbour_wt==distance[neighbour])
            {
                // I will not push it to PQ as this case will already be covered 
                ways[neighbour]+=ways[node];
            }
            if(distance_till_now+neighbour_wt<distance[neighbour])
            {
                //When a better distance is found the change number of ways to the no. of ways of prev node from where we are coming
                ways[neighbour]=ways[node];

                distance[neighbour]=distance_till_now+neighbour_wt;
                pq.push({distance[neighbour],neighbour});
            }
        }
    }
    return ways[n-1];
}

int main()
{
    int n;
    cin>>n;

    int edges;
    cin>>edges;

    //since this is a weighted graph so it'll have node as well as its weight in the adj list
    vector<vector<pair<int,int> > > arr(n);

    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        //This is a directed graph
        arr[u].push_back(make_pair(v,w));
    }

    int src,dest,k;//the source node,dest node and max numer of steps
    cin>>src;

}