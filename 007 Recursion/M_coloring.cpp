// Problem Link : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// Video : https://youtu.be/wuVwUK25Rfc?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

//This is a permutation similar problem , just try out all possibilities 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool graphColoring(bool graph[101][101], int m, int n,int curr_node,int color[])
    {
        //starting from 0 if we reach n that means we have succesfully colored all nodes
        if(curr_node==n)
        return true;
        else
        {
            for(int c=0;c<m;c++)
            {
                int flag_safe=1;
                
                 //Iterating over each neighbour to check that both the nodes don't have same color , i.e if there is an edge and colors are same then unsafe otherwise safe
                for(int j=0;j<n;j++)
                {
                    if(graph[curr_node][j]==1 && j!=curr_node && color[j]==c)
                    {
                        flag_safe=0;
                        break;
                    }
                }
                if(flag_safe)
                {
                    color[curr_node]=c;
                    bool can_be_colored=graphColoring(graph,m,n,curr_node+1,color);
                    color[curr_node]=-1;
                        
                    if(can_be_colored)
                    return true;
                }
            }
            
        }
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n],visited[n];
        //initially all vertices are un-colored (-1)
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        return graphColoring(graph,m,n,0,color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends