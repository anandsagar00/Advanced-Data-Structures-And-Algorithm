#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<stack>

using namespace std;

void minSpanTreePRIMS(vector<vector<pair<int,int> > > &arr,int n)
{
    vector<int> visisted(n,0);

    vector<pair<int,int> > MST; // this will store the Minimum Spanning Tree in form of edges

    //In this we will be storing the { Weight , Current Node , Parent Node }
    priority_queue<vector<int>,vector<vector<int> > ,greater<vector<int> > > pq;

    pq.push({0,0,-1});//    -1 indicates that it is the first node

    int sum=0;//this is going to store the weight of the MST

    while(!pq.empty() && MST.size()<n-1)
    {
        vector<int> details=pq.top();
        pq.pop();

        int wt=details[0];
        int node=details[1];
        int parent=details[2];

        if(parent!=-1 && visisted[node]==0)
        {
            MST.push_back(make_pair(parent,node));
            sum+=wt;
        }

        if(!visisted[node])
        {
            visisted[node]=1;
            //if the node was not visited , then we will iterate over all its unvisited neighbours

            for(auto &neighbours:arr[node])
            {
                int neighbour_node=neighbours.first;
                int neighbour_wt=neighbours.second;

                if(!visisted[neighbour_node])
                {
                    pq.push({neighbour_wt,neighbour_node,node});
                }
            }
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
    int n;//number of vertices
    cin>>n;

    vector<vector<pair<int,int> > > arr(n);
    int edg;//number of edges
    cin>>edg;

    for(int i=0;i<edg;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        arr[u].push_back(make_pair(v,w));
        arr[v].push_back(make_pair(u,w));
    }
    minSpanTreePRIMS(arr,n);
}