// Context : https://youtu.be/R6uoSjZ2imo?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
// Problem : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

/*
https://www.geeksforgeeks.org/strongly-connected-components/

If in a sub-graph of a graph all nodes can be reached from the other it is called Strongly Connected Component

Now logic is simple : Since all the nodes in a Strongly component can be reached to one another in a cyclic manner
                      so , reversing the edges of graph won't make any effect in getting the strongly componnet

                        I can't explain in writing.....refer to Striver's video for detailed explanation

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include<unordered_map>
using namespace std;


class Solution
{
	public:
	
	void DFS_finishing_time(vector<vector<int>>& adj,vector<int> &visited,stack<int> &st,int i)
	{
	    //This function will calculate the finishing time for DFS for each node , so the one to finish at last will be at top of stack
	    visited[i]=1;
	    
	    for(auto &neighbour:adj[i])
	    {
	        if(!visited[neighbour])
	        {
	            DFS_finishing_time(adj,visited,st,neighbour);
	        }
	    }
	    st.push(i);
	}
	
	void DFS(vector<vector<int>>& adj,vector<int> &visited,int i)
	{
	    //This function will calculate the finishing time for DFS for each node , so the one to finish at last will be at top of stack
	    visited[i]=1;
	    
	    for(auto &neighbour:adj[i])
	    {
	        if(!visited[neighbour])
	        {
	            DFS(adj,visited,neighbour);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        vector<int> visited(n,0);
        stack<int> st;
        
        /*
        I will first calculate the finishing time for all nodes , so that after reversing the edges of a graph , we start from the node which
        took the most time to finish , as after reversing that will be the node which would take least time , or which would be the first node
        */
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            DFS_finishing_time(adj,visited,st,i);
        }
        
        //I will be using this visited array again later so marking all as unvisited
        for(int i=0;i<n;i++)
        visited[i]=0;
        
        // Now we will reverse the graph
        
        vector<vector<int> > arr(n);
        
        for(int i=0;i<n;i++)
        {
            for(auto &it:adj[i])
            {
                arr[it].push_back(i);
            }
        }
        
        int count=0;//this will store the count of components 
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            
            if(!visited[node])
            {
                DFS(arr,visited,node);
                count++;
            }
        }
        return count;
        
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
