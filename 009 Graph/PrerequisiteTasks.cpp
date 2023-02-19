// Context : https://youtu.be/WAOfKpxYHR8?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

//This problem is very similar to job scheduling or process scheduling

/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites,
for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P,
find if it is possible to finish all tasks.
*/

//TOPOLOGICAL SORT is the solution , if TOPO sort can be done then it's okay , otherwise not
// or detect cycle any method

/*
There is one more question very similar to this : https://practice.geeksforgeeks.org/problems/course-schedule/1
It not only asks whether jobs can be done or not but also , the order
*/

#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <utility>
#include <set>
using namespace std;


void BFS(vector<vector<int> > &arr,vector<int> &indegree,vector<int> &sorted)
{
    //This function performs TOPO sort
    queue<int> q; // queue that will store elements with indegree 0

    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        sorted.push_back(node);

        for(auto &neighbour:arr[node])
        {
            indegree[neighbour]-=1;//decreasing the indegree of all adjacent nodes
            if(indegree[neighbour]==0)
            {
                q.push(neighbour);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > arr(n);

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        //this is a directed graph so the edges will be uni-directional
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }
    vector<int> indegree(n,0);

    //this will calculate the indegree of all nodes
    //this will calculate the indegree of all nodes
    for(int i=0;i<n;i++)
    {
        for(auto &nodes:arr[i])
        indegree[nodes]++;
    }

    vector<int> ans;
    BFS(arr,indegree,ans);

    if(ans.size()==n)
    cout<<"Yes it can be scheduled\n";
    else
    cout<<"No , it can not be scheduled\n";
}