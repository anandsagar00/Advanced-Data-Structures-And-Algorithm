/*
The video below will teach you a lot about the following :
Discovery Time , Lowest Discovery Node reachable etc.. which would be useful for Striver's video
*/

// Tarzan's alg : https://youtu.be/ZeDNSeilf-Y (Just see what is discovery time and what is lowest discovery time node available and nothing else)

// Context : https://youtu.be/qrAub5z8FeA?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem Link : https://leetcode.com/problems/critical-connections-in-a-network/


/*
Approach : We will create two arrays , one which would store the discovery time of the node
and 
The second which would store the lowest discovery time of neighbour node (except parent)
*/

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std; 

class Solution {
public:

    int DFS(int node,vector<vector<int>> &arr,vector<int> &visited,vector<int> &discovery_time,vector<int> &lowest_discovery_time_neighbour,int parent,int &time)
    {
        visited[node]=1;
        //initially we are filling both discovery time and lowest discovery time of neighbour as the discover time
        discovery_time[node]=time;
        lowest_discovery_time_neighbour[node]=time;

        for(auto &neighbor:arr[node])
        {
            //if neighbour has been visited then check if it has lower discovery time , if yes then update
            if(visited[neighbor] && neighbor!=parent)
            {
                lowest_discovery_time_neighbour[node]=min(lowest_discovery_time_neighbour[node],lowest_discovery_time_neighbour[neighbor]);
            }
            else if(!visited[neighbor])
            {
                time++;
                lowest_discovery_time_neighbour[node]=min(DFS(neighbor,arr,visited,discovery_time,lowest_discovery_time_neighbour,node,time),lowest_discovery_time_neighbour[node]);
            }
        }
        return lowest_discovery_time_neighbour[node];
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //connections is basically the array of edges {u,v} , so we will be forming a graph [adj list] out of it

        vector<vector<int>> arr(n);

        //forming  ADJ list 
        for(auto &vec:connections)
        {
            int u=vec[0];
            int v=vec[1];
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        vector<int> visited(n,0);
        vector<int> discovery_time(n,-1);
        vector<int> lowest_discovery_time_neighbour(n,-1);
        int time=1;
        DFS(0,arr,visited,discovery_time,lowest_discovery_time_neighbour,-1,time);

        int bridge_count=0;

        /*
        I will be iterating over each of the edges in graph and I will check....
        If current node was discovered before the lowest discovery time of neighbour nodes then that is a bridge

        If the lowest discovery time of neighbour is smaller than or equal to discovery time of current node
        than that means that there is yet another path via which we can reach the other end of the eedge , hence not a bridge
        */
        
        vector<vector<int>> ans;//this will store all the bridges

       for(auto &vec:connections)
       {
            int u=vec[0];
            int v=vec[1];
            if(discovery_time[min(u,v)]<lowest_discovery_time_neighbour[max(u,v)])
            {
                //This means I can't reach the node v apart from this edge
                bridge_count++;
                ans.push_back({u,v});
            }
       }
        return ans;
    }
};