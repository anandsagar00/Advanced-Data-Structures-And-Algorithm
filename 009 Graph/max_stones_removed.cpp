// Context : https://youtu.be/OwMNX8SPavM?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem : https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

// Pre-req :  DSU , union by size


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<queue>
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
        size.resize(n,1);
        parent.resize(n);

        //initially all nodes will be parent to itself
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int findUltimateParent(int i)
    {
        if(parent[i]==i)
        return i;
        else
        return parent[i] = findUltimateParent(parent[i]);
    }

    void unionBySize(int u,int v)
    {
        int ult_par_u=findUltimateParent(u);
        int ult_par_v=findUltimateParent(v);

        //if Ultimate Parents are same then they are already united
        if(ult_par_u==ult_par_v)
        return;
        else
        {
            if(size[ult_par_u]<size[ult_par_v])
            {
                //then we will attach smaller one to the bigger one
                parent[ult_par_u]=ult_par_v;
                size[ult_par_v]+=size[ult_par_u];
            }
            else
            {
                parent[ult_par_v]=ult_par_u;
                size[ult_par_u]+=size[ult_par_v];
            }
        }
    }

    int findSize(int i)
    {
        int ult_parent_i = findUltimateParent(i);
        return size[ult_parent_i];
    }

};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        //TODO : (Watch Video as well as implement)
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}