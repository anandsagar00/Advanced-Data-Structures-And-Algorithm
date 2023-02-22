// Context : https://youtu.be/9XybHVqTHcQ?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem Link : https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops

/*
There are n cities and m edges connected by some number of flights.
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1
*/

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int infinity=9999999;

int shortest_path_k_stops(vector<vector<pair<int,int> > > &arr,int src,int dest,int k)
{
    int n=arr.size();
    
    vector<int> distance(n,infinity); // creating a distance array which has INF initially

    distance[src]=0;

    //Now I will be using a queue
   // which will have distance till now , NODE and total nodes from SRC to DEST(which has to be at max k-2)

//  [Note : I used a queue not a PQ as PQ becomes greedy and doesn't try all possible combinations]
//  where as queue tries have all combinations ( https://youtu.be/3dINsjyfooY?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn )

   queue<vector<int> > pq;

   pq.push({0,src,1}); // distance = 0,source node as SRC  , and number of nodes =1

   while(!pq.empty())
   {
        vector<int> detail=pq.front();
        pq.pop();

        int distance_till_now=detail[0];
        int node=detail[1];
        int total_nodes=detail[2];

        for(auto &neighbours:arr[node])
        {
            //First we will check total nodes till now should be LESS than k+2 as we will add more nodes in this step
            if(total_nodes-2<k)
            {
                int neighbour=neighbours.first;
                int neighbour_wt=neighbours.second;

                if(distance_till_now+neighbour_wt<distance[neighbour])
                {
                    distance[neighbour]=distance_till_now+neighbour_wt;
                    pq.push({distance[neighbour],neighbour,total_nodes+1});
                }
            }
        }
   }
   if(distance[dest]==infinity)
   return -1;
   else
   return distance[dest];
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