// Context : https://youtu.be/3oI-34aPMWM?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// In this program I will be writing code for ADJACENCY-MATRIX representation of graph 

/*

Lets suppose we have 5 nodes (numbered from 0-4)

and 6 edges , which are 

0 1
1 3
3 2
2 0
1 4
4 3

*/

#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int> > &adj_mat)
{
    cout<<"\n";
    for(auto &vectors:adj_mat)
    {
        for(auto numbers:vectors)
        cout<<numbers<<" ";
        cout<<"\n";
    }
}

int main()
{
    int n;//to store number of vertices

    cin>>n;

    vector<vector<int> > adj_mat(n,vector<int>(n,0));//this will create a 2-d array of nxn and will fill all cells by zero

    int edges;//to store the count of edges
    cin>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v;//in this I'll be store starting point and ending point of edge
        cin>>u>>v;

        //Since this is an undirected graph so we will mark twice as the same edge will be connecting both notes from both sides
        adj_mat[u][v]=1;
        adj_mat[v][u]=1;
    }

    printMatrix(adj_mat);
}