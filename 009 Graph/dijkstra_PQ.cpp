#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int infinity=99999;//defining the infinity as a very large num , so that it can never be our answer

void shortestPath(vector<vector<pair<int,int> > > &arr,vector<int> &distance,int src)
{
    //We will create a Priority queue where I will be storing the weight associated with node value
   //first element is edge wt and second is node
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;//min PQ

    pq.push(make_pair(0,src));
    distance[src]=0;

    while(!pq.empty())
    {
        int distance_till_now=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        // Now I'll iterate over all the neighbouring nodes of the current node
        // and I will check , if we can reach to that node in shorter ditance then we will update the ditance

        for(auto &neighbours:arr[node])
        {
            int neighbour_node=neighbours.first;
            int neighbour_wt=neighbours.second;

            if(distance_till_now+neighbour_wt<distance[neighbour_node])
            {
                distance[neighbour_node]=distance_till_now+neighbour_wt;
                pq.push(make_pair(distance[neighbour_node],neighbour_node));
            }
        }
    }
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

        arr[u].push_back(make_pair(v,w));
        arr[v].push_back(make_pair(u,w));
    }

    int src;//the source node from where we have to start the shortest path algorithm
    cin>>src;

    vector<int> distance(n,infinity);
    shortestPath(arr,distance,src);

    for(auto &it:distance)
    cout<<it<<" ";
    cout<<"\n";
}