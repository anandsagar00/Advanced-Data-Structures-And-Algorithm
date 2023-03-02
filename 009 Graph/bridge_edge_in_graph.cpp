// Pre-Requisite : Tarzan's alg , Bridges in graph

// Problem Link : https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    
    int DFS(int node,vector<int> &visited,vector<int> arr[],vector<int> &LDTN,vector<int> &DT,int &time,int parent)
    {
        visited[node]=1;
        LDTN[node]=DT[node]=time;
        
        for(auto &neigh:arr[node])
        {
            if(neigh==parent) continue;
            
            if(visited[neigh])
            {
                LDTN[node]=min(LDTN[node],LDTN[neigh]);
            }
            else
            {
                time++;
                LDTN[node]=min(LDTN[node],DFS(neigh,visited,arr,LDTN,DT,time,node));
            }
        }
        return LDTN[node];
    }
    
    int isBridge(int n, vector<int> adj[], int u, int v) 
    {
        //Three arrays one for visited , one for lowest discovery time neighbour , one for discovery time of current node

        vector<int> visited(n,0),LDTN(n,0),DT(n,0);
        
        int time=1;
        DFS(min(u,v),visited,adj,LDTN,DT,time,-1);
        if(DT[min(u,v)]<LDTN[max(u,v)])
        return 1;
        else
        return 0;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}