//Context : https://youtu.be/rp1SMw7HSO8?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int infinity=9999999;//defining the infinity as a very large num , so that it can never be our answer

void shortestPath(vector<vector<pair<int,int> > > &arr)
{
    // [There are slight modification in GFG in terms of returning and printing , but this is the logic]

    int src=0;
    int n=arr.size();

    // [Note : Where I am coming from]

    //This vector will not only store the shortest path weight but also from where it has come
    vector<pair<int,int> > distance(n,make_pair(infinity,-1));//first is wt and 2nd is node

    //We will create a Priority queue where I will be storing the weight associated with node value
   //first element is edge wt and second is node
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;//min PQ

    pq.push(make_pair(0,src));
    distance[src]=make_pair(0,-1);

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

            if(distance_till_now+neighbour_wt<distance[neighbour_node].first)
            {
                //In this line I am storing the updated weight
                distance[neighbour_node].first=distance_till_now+neighbour_wt;
                //in the line below I am storing from where I am coming from
                distance[neighbour_node].second=node;
                pq.push(make_pair(distance[neighbour_node].first,neighbour_node));
            }
        }
    }
    //We have to print the shortest path from 0th node to n-1th node
    if(distance[n-1].second==-1)
    {
        cout<<"We can't reach there\n";
    }
    else
    {
        int j=n-1;
        cout<<j<<" ";
        while(j!=0)
        {
            cout<<distance[j].second<<" ";
            j=distance[j].second;
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
    shortestPath(arr);
}