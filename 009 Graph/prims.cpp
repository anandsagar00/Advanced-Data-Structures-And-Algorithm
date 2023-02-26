#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<stack>

using namespace std;

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
}