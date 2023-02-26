// Context : https://youtu.be/DMnDM_sxVig?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Pre-Requisite : Disjoint Set Union (By Rank or By Size with Path compression preferred)

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

//This is a Disjoint Set Data-Structure class 
class DisjointSet
{
    vector<int> parent;//this will store the parent of a node
    vector<int> rank;//this will store the rank of a given node
    public:
    
    //Constructer to initialise the initial rank and initial parent
    DisjointSet(int n)
    {
        //using n+1 so that it can work with Graphs with node which has 1 based indexing as well
        parent.resize(n+1);
        rank.resize(n+1,0);//initially the rank of all nodes will be 0

        //Initially all nodes will be parent to itself
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }

    //This function will find the ultimate parent of a node recursively using Path Compression
    int findUltimateParent(int node)
    {
        //If the parent node of a node is node itself , then return node as it itself is the parent
        if(parent[node]==node)
        return node;
        else
        {
            // find the parent of the parent recursively and save compress the path
            return parent[node]=findUltimateParent(parent[node]);
        }
    }

    void unionByRank(int u,int v)
    {
        int ult_p_u=findUltimateParent(u);
        int ult_p_v=findUltimateParent(v);

        //If both the nodes have same ultimate parent then they are already connected
        if(ult_p_u==ult_p_v)
        return ;
        else
        {
            //Connect the smaller ranked component to the larger one
            if(rank[ult_p_u]<rank[ult_p_v])
            {
                //rank will not change
                parent[ult_p_u]=ult_p_v;
            }
            else if(rank[ult_p_v]<rank[ult_p_u])
            {
                parent[ult_p_v]=ult_p_u;
            }
            else
            {
                // when both are of same rank , then we can add any one to anyone but we will have to increase rank by 1
                parent[ult_p_u]=ult_p_v;
                rank[ult_p_v]++;
            }
        }

    }
};

void kruskal(vector<vector<int> > edges,int n)
{
    //first we will sort the edges 
    sort(edges.begin(),edges.end());

    vector<pair<int,int> > MST; // this will store the Minimum Spanning Tree in form of edges

    //we will also create a Disjoint Set Data Structure
    DisjointSet DS(n);

    int sum=0;//to store MST weight

    //we know that there can be n-1 edges in a MST 

    for(int i=0;i<edges.size() && MST.size()<=n-1 ;i++)
    {
        int wt=edges[i][0];
        int u=edges[i][1];
        int v=edges[i][2];

        if(DS.findUltimateParent(u)!=DS.findUltimateParent(v))
        {
            sum+=wt;

            //this means both are not connected
            DS.unionByRank(u,v);
            MST.push_back({u,v});
        }
    }

    cout<<"\nThe MST weight is : "<<sum<<"\n";

    cout<<"The edges of MST are : \n";
    for(auto &edges:MST)
    {
        cout<<"( "<<edges.first<<" , "<<edges.second<<" )\n";
    }

}

int main()
{
    int n; // number of nodes
    cin >> n;

    int E; // number of edges
    cin>>E;
    vector<vector<int> > edges; // I will be storing U,V,W in this vector

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        //this is a modifies edge array in which I am storing Weight first , so that we can use inbuilt STL sort easily
        edges.push_back({w, u, v}); // this creates a vector of size 3 by default
    }
    kruskal(edges,n);
}