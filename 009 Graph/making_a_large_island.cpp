// Context : https://youtu.be/lgiz0Oup6gM?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem Link : https://practice.geeksforgeeks.org/problems/maximum-connected-group/1

// Pre-req :  DSU , union by size

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<unordered_map>
using namespace std;

class DisjointSet
{
    vector<int> size;
    vector<int> parent;

    public:
    //constructor to initialise default values
    DisjointSet(int n)
    {
        size.resize(n,0);
        parent.resize(n);

        //initially all nodes will be parent to itself
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
}


class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}