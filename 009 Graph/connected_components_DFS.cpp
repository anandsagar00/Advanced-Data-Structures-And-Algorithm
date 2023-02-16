// Context : https://youtu.be/lea-Wl_uWXY?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

//Connected Comp : https://www.baeldung.com/cs/graph-connected-components

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

Output : 

0 1 3 2 
4 6 5 
7 8 
9
*/

#include<iostream>
#include<vector>
using namespace std;

void getConnectedCompDFS(vector<vector<int> > &adj,vector<int> &visited,vector<int> &currComp,int i)
{
    if(visited[i]==1)
    return;
    else
    {
        //marks node as visited, add it to currComp list , and perform DFS on its adj list
        visited[i]=1;
        currComp.push_back(i);
        for(auto &nodes:adj[i])
        {
            getConnectedCompDFS(adj,visited,currComp,nodes);
        }
    }
}

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
    vector<int> currentComponent; //this will store current component in current DFS
    vector<vector<int> > components; // this will store all components

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            //this function will get the current component and we will push it to components 2d-vector
            getConnectedCompDFS(adj,visited,currentComponent,i);
            components.push_back(currentComponent);

            currentComponent.clear();
        }
    }
    printAllComponents(components);
}