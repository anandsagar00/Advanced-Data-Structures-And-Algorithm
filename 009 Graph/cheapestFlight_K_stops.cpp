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

    /*
    I will be creating a priority queue , which will store {STOPS,NODE,DISTANCE} ,
    since here our priority will be number of stops and not distance , if we consider PQ of distance 
    then we will get wrong result
    */

   priority_queue<vector<int> ,vector<vector<int> > ,greater<vector<int> > > pq;

   pq.push({0,src,0}); // stops = 0 , node = src , dist = 0

   while(!pq.empty())
   {
        vector<int> detail=pq.top();
        pq.pop();

        int stops=detail[0];
        int node=detail[1];
        int distance_till_now=detail[2];

        for(auto &neighbours:arr[node])
        {
            //First we will check total stops is <= K
            if(stops<=k)
            {
                int neighbour=neighbours.first;
                int neighbour_wt=neighbours.second;

                if(distance_till_now+neighbour_wt<distance[neighbour])
                {
                    distance[neighbour]=distance_till_now+neighbour_wt;
                    pq.push({stops+1,neighbour,distance[neighbour]});
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