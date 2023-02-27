// Context : https://youtu.be/FMwpt_aQOGw?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem Link : https://practice.geeksforgeeks.org/problems/account-merge/1

#include <iostream>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
#include<unordered_map>
using namespace std;

// This is a Disjoint Set Data-Structure class
class DisjointSet
{
    vector<int> parent; // this will store the parent of a node
    vector<int> rank;   // this will store the rank of a given node
public:
    // Constructer to initialise the initial rank and initial parent
    DisjointSet(int n)
    {
        // using n+1 so that it can work with Graphs with node which has 1 based indexing as well
        parent.resize(n + 1);
        rank.resize(n + 1, 0); // initially the rank of all nodes will be 0

        // Initially all nodes will be parent to itself
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // This function will find the ultimate parent of a node recursively using Path Compression
    int findUltimateParent(int node)
    {
        // If the parent node of a node is node itself , then return node as it itself is the parent
        if (parent[node] == node)
            return node;
        else
        {
            // find the parent of the parent recursively and save compress the path
            return parent[node] = findUltimateParent(parent[node]);
        }
    }

    void unionByRank(int u, int v)
    {
        int ult_p_u = findUltimateParent(u);
        int ult_p_v = findUltimateParent(v);

        // If both the nodes have same ultimate parent then they are already connected
        if (ult_p_u == ult_p_v)
            return;
        else
        {
            // Connect the smaller ranked component to the larger one
            if (rank[ult_p_u] < rank[ult_p_v])
            {
                // rank will not change
                parent[ult_p_u] = ult_p_v;
            }
            else if (rank[ult_p_v] < rank[ult_p_u])
            {
                parent[ult_p_v] = ult_p_u;
            }
            else
            {
                // when both are of same rank , then we can add any one to anyone but we will have to increase rank by 1
                parent[ult_p_u] = ult_p_v;
                rank[ult_p_v]++;
            }
        }
    }

    // This function will return the total number of components till now
    // The number of unique ultimate parent will be the number of components
    int numberOfComponents()
    {
        set<int> st; // this is to store total unique elements

        // Assuming that the graph follows 0 based indexing , since array is of n+1 size so iterating from [0,n-1)

        for (int i = 0; i < parent.size()-1; i++)
            st.insert(findUltimateParent(i));

        return st.size();
    }
};

class Solution{
  public:
    vector<vector<string> > accountsMerge(vector<vector<string> > &accounts) {
        int n=accounts.size();
        DisjointSet DS(n);

        //In this unordered map I will be mapping email IDs to the names [Here I have taken name as integer 0,1,2 etc]
        unordered_map<string,int> ump;

        for(int i=0;i<n;i++)
        {
            string name=accounts[i][0];
            for(int j=1;j<accounts[i].size();j++)
            {
                if(ump.find(accounts[i][j])==ump.end())
                {
                    //the mail doesn't exist yet in the Unordered Map
                    ump[accounts[i][j]]=i;
                }
                else
                {
                    //If a email already exists then , we will do Union of those 2 nodes
                    DS.unionByRank(ump[accounts[i][j]],i);
                }
            }
        }
        
        int unique_count=DS.numberOfComponents();//This will tell us the total number of names we require

        vector<vector<string> > ans(unique_count);

        for(auto &it:ump)
        {
            string mail=it.first;
            int name_index=it.second;

            int ult_p=DS.findUltimateParent(name_index);//We will find ultimate parent of the name index and then insert into that position in ans variable

            if(ans[ult_p].size()==0)
            {
                //that means that the name has not yet been entered
                ans[ult_p].push_back(accounts[ult_p][0]);//this will insert name into the ans 
            }

            ans[ult_p].push_back(mail);

        }

        //now the sorting part
        for(int i=0;i<unique_count;i++)
        sort(ans[i].begin()+1,ans[i].end());
        return ans;
    }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string> > accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string> > res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}