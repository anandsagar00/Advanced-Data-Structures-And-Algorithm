//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define INF 999999

class Solution {
  public:
    int findCity(int n, int edg, vector<vector<int>>& edges,int thresh) {
            
    vector<vector<int> > arr(n,vector<int>(n,INF));//ADJ MAT

    for(int i=0;i<edg;i++)
    {
        int u=edges[i][0],v=edges[i][1],w=edges[i][2];

        //This is an undirected weighted graph
        arr[u][v]=w;
        arr[v][u]=w;
    }
    
    for(int i=0;i<n;i++)
    {
      arr[i][i]=0;
    }

    for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][k] != INF && arr[k][j] != INF)
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     cout<<arr[i][j]<<" ";
    //     cout<<"\n";
    // }
    
    int city=-1;
    int min_city_count=n;

    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]<=thresh)
            count++;
        }
        if(count<=min_city_count)
        {
            min_city_count=count;
            city=i;
        }
    }
    return city;
    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends