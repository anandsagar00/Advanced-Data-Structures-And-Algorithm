// Context : https://youtu.be/ACzkVtewUYA?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

/*
N=10
Edges=8

edges details : 

0 1
1 3
3 2
2 0
4 6
6 5
5 4
7 8

Output : 4 
as there are 4 provinces in the graph
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<vector<int> > &adj,vector<int> &visited,int i)
{
    //this function will perform BFS starting from a gien node i
    queue<int> q;
    q.push(i);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        //if the node is not visited then only perform BFS , other wise not
        if(!visited[node])
        {
            //first mark node as visited
            visited[node]=1;

            for(auto &nodes:adj[node])
            {
                if(!visited[nodes])
                {
                    q.push(nodes);
                }
            }
        }
    }
}

/*
void printAllComponents(vector<vector<int> > &components)
{
    //function to print all componnets
    cout<<"\n";
    for(auto &component:components)
    {
        for(auto &nodes:component)
        cout<<nodes<<" ";

        cout<<"\n";
    }
}
*/
int main()
{
    int n;//to store number of vertices

    cin>>n;

    //This will create an empty 2d vector
    vector<vector<int> > adj(n);

    int edges;//to store the count of edges
    cin>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v;//in this I'll be store starting point and ending point of edge
        cin>>u>>v;

        //Since this is an undirected graph so we will mark twice as the same edge will be connecting both notes from both sides
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }

    vector<int> visited(n,0);//this will store the status whether the node has been visited or not

    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            //this function will do BFS starting from current node
            BFS(adj,visited,i);
            count++;
        }
    }
    cout<<count<<"\n";
}