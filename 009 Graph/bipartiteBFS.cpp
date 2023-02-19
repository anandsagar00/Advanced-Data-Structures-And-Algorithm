// Context : https://youtu.be/-vu34sct1g8?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

//Problem link : https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<set>
using namespace std;

bool checkBipartite(vector<vector<int> > &arr,int n,vector<int> &visited,int start,vector<int> &color)
{
    queue<int> q; 
    q.push(start);

    while(!q.empty())
    {
        int curr_node=q.front();
        q.pop();

        if(!visited[curr_node])
        {
            visited[curr_node]=1;
            
            if(color[curr_node]==-1)
            {
                //if there is no any color assigned then assign a color
                color[curr_node]=1;
            }

            for(auto &node:arr[curr_node])
            {
                //traversing over all the adjacent nodes of the current node
                if(!visited[node])
                q.push(node);

                if(color[node]==-1)
                {
                    //If the node is un-colored then assign a color which is different from curr node
                    if(color[curr_node]==1)
                    color[node]=2;
                    else
                    color[node]=1;
                }
                else if(color[node]==color[curr_node])
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int> > arr(n);

    int edges;
    cin>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    bool isBipartite=true;

    /*
    IMP : Declaring color and visited array in main 
    (any function which will call checkBipartite again and again) is very imp as it will check for all componets of graph
    and when you declare color array everytime in checkBipartite function it consumes a lot of time
    */
    vector<int> visited(n,0);
    vector<int> color(n,-1);//this will stor the colors assigned to each node , -1 uncolored , 1 color1,2 color2
    //initially all nodes will be un-colored

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(!checkBipartite(arr,n,visited,i,color))
            {
                isBipartite=false;
                break;
            }
        }
    }

    if(!isBipartite)
    cout<<"NO\n";
    else
    cout<<"YES\n";
    
}
