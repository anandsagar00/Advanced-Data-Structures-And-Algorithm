// Context : https://youtu.be/PATgNiuTP20?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int infinity=99999;//defining the infinity as a very large num , so that it can never be our answer

void shortestPath(vector<vector<pair<int,int> > > &arr,vector<int> &distance,int src)
{
    //We will use SET this time 

    //SET keeps all the elements in ascending order and also keeps smallest at TOP
    set<pair<int,int> > st; // In pair we are storing weight and the corresponding node

    /*
    In set if we find a better {weight,node} pair then we will erase the one which is not good
    this will save us several iterations in future , which could not have been done in case of Priority Queue
    */

    st.insert(make_pair(0,src));
    distance[src]=0;

    while(!st.empty())
    {
        int distance_till_now=st.begin()->first;
        int node=st.begin()->second;
        st.erase(st.begin());

        // Now I'll iterate over all the neighbouring nodes of the current node
        // and I will check , if we can reach to that node in shorter ditance then we will update the ditance

        for(auto &neighbours:arr[node])
        {
            int neighbour_node=neighbours.first;
            int neighbour_wt=neighbours.second;

            if(distance_till_now+neighbour_wt<distance[neighbour_node])
            {
                //since we found a better soln,we are searching for older {weight,node} pair
               // if that exists then we will erase that from set
                auto itr=st.find(make_pair(neighbour_wt,neighbour_node));
                
                if(itr!=st.end())
                st.erase(itr);

                distance[neighbour_node]=distance_till_now+neighbour_wt;
                st.insert(make_pair(distance[neighbour_node],neighbour_node));
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    int edges;
    cin>>edges;

    //since this is a weighted graph so it'll have node as well as its weight in the adj list
    vector<vector<pair<int,int> > > arr(n);

    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        arr[u].push_back(make_pair(v,w));
        arr[v].push_back(make_pair(u,w));
    }

    int src;//the source node from where we have to start the shortest path algorithm
    cin>>src;

    vector<int> distance(n,infinity);
    shortestPath(arr,distance,src);

    for(auto &it:distance)
    cout<<it<<" ";
    cout<<"\n";
}