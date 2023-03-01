// Context : https://youtu.be/lgiz0Oup6gM?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem Link : https://practice.geeksforgeeks.org/problems/maximum-connected-group/1

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

    int convert_coord_to_index_in_DSU(int i,int j,int m)
    {
        int ans=(i*m)+j;
        return ans;
    }

    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();

        DisjointSet DS(n*n);

        //Moves : Left , Right , Up , Down
        vector<pair<int,int> > moves={{0,-1},{0,1},{-1,0},{1,0}};

        // First I will try to do Union of all the 1s and form a Disjoint Set

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {

                if(grid[i][j]==0)
                continue;

                // Now we will move in all 4 directions and we will make union if there is a 1

                for(auto &move:moves)
                {
                    int new_x=i+move.first;
                    int new_y=j+move.second;

                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<n && grid[new_x][new_y]==1)
                    {
                        int u = convert_coord_to_index_in_DSU(i,j,n);
                        int v = convert_coord_to_index_in_DSU(new_x,new_y,n);
                        
                        DS.unionBySize(u,v);
                    }
                }
                
            }
        }

        // Now I will try to make a large island by traversing on all Zeros , and we will not union but check how many 1s are there on all 4 of it's side 

        int max_size=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // we will only be travelling on Zeros
                if(grid[i][j]==1)
                continue;

                set<int> st;//this set will store ultimate parents of all 1s on all it's 4 sides

                // Now we will move in all 4 directions and we will not make union if there is a 1 , instead just we will insert ultimate parents into the set , so that we can count the total 1s later

                for(auto &move:moves)
                {
                    int new_x=i+move.first;
                    int new_y=j+move.second;

                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<n && grid[new_x][new_y]==1)
                    {
                        int u = convert_coord_to_index_in_DSU(new_x,new_y,n);
                        
                        // We will not union , just we will insert ultimate parents into the set , so that we can count the total 1s later
                        st.insert(DS.findUltimateParent(u));
                    }
                }
                
                int temp_size=0;

                for(auto &element:st)
                {
                    temp_size+=DS.findSize(element);
                }

                // we are adding 1 as the 0 himself will be converted to 1 , so counting that as well
                max_size=max(max_size,1+temp_size);

            }
        }

        // I have to handle 1 more case , what if already whole grid is already connected then we will traverse once more and update the values

        for(int i=0;i<n*n;i++)
        max_size=max(max_size,DS.findSize(i));

        return max_size;

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