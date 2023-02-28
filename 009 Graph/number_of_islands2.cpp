// Context : https://youtu.be/Rn6B-Q4SNyA?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem Link : https://practice.geeksforgeeks.org/problems/number-of-islands/1

// Pre-Requisites : Disjoint Set Data Structure

#include <bits/stdc++.h>
using namespace std;



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
};

class Solution {
  public:
  
  int convert_coordinate_to_node_id(int i,int j,int m)
{
    int ans=(i*m)+j;
    return ans;
}
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        /*
        total number of cells would be n*m , so we will create a Disjoint Set Data Structure of n*m size
        
        each cell would be given a node id , where it will be numbered from 0 to n*m-1
        
        node_id=(current_row*m)+current_col
        */
        DisjointSet DS(n*m);
        
        vector<vector<int> > visited(n,vector<int>(m,0));//to keep track of visited cells
        
        //Moves : left , right , up , down
        vector<pair<int,int>> moves={{0,-1},{0,1},{-1,0},{1,0}};
        
        int total_components=0;
        
        vector<int> ans;
        
        for(auto &vec:operators)
        {
            int i=vec[0];
            int j=vec[1];
            
            if(visited[i][j]==1)
            {
                ans.push_back(total_components);
                continue;
            }
            else
            {
                visited[i][j]=1;
                total_components+=1;//as soon as a single cell is made into an island , a new component is added , later we check if it is already a part of some other comp then we decrease the count
                
                //If the cell is not visited then iterate on all 4 sides (left , right , up , down) and then do union if component is found
                
                for(auto &move:moves)
                {
                    int new_x=i+move.first;
                    int new_y=j+move.second;
                    
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m)
                    {
                        //this means we are inside the cell
                        if(visited[new_x][new_y]==1)
                        {
                            //if the cell is visited that means that is a land , so we will union current cell and this visited cell
                            int u=convert_coordinate_to_node_id(i,j,m);
                            int v=convert_coordinate_to_node_id(new_x,new_y,m);
                            if(DS.findUltimateParent(u)!=DS.findUltimateParent(v))
                            {   
                                //If the parent of current and neighbouring cells are not same then only union 
                                DS.unionByRank(u,v);
                                total_components-=1;//the moment we do union , then total components would decrease
                            }
                            else
                            {
                                //If the parent of current and neighbouring cells not same then we will do the union but not increase the comp 
                                DS.unionByRank(u,v);
                            }
                        }
                    }
                    
                }
                ans.push_back(total_components);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}