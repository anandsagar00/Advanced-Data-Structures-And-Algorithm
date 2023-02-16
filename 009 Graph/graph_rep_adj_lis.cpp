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

Output : 

[ 0 ] : 1 2 
[ 1 ] : 0 3 4 
[ 2 ] : 3 0 
[ 3 ] : 1 2 4 
[ 4 ] : 1 3

explanation : This shows that with 0th node , node 1 and node 2 are connected and so on 

*/

#include<iostream>
#include<vector>
using namespace std;

void printList(vector<vector<int> > &adj_mat)
{
    cout<<"\n";
    int i=0;
    for(auto &vectors:adj_mat)
    {
        cout<<"[ "<<i<<" ] : ";
        for(auto numbers:vectors)
        cout<<numbers<<" ";
        cout<<"\n";
        i+=1;
    }
}

int main()
{
    int n;//to store number of vertices

    cin>>n;

    //This will create an empty 2d vector
    vector<vector<int> > adj_list(n);

    int edges;//to store the count of edges
    cin>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v;//in this I'll be store starting point and ending point of edge
        cin>>u>>v;

        //Since this is an undirected graph so we will mark twice as the same edge will be connecting both notes from both sides
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
    }

    printList(adj_list);
}