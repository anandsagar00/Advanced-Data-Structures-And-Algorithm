// Context : https://youtu.be/U3N_je7tWAs?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

//Practice link : https://practice.geeksforgeeks.org/problems/alien-dictionary/1

//This is also an application of TOPO sort

/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, 
thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
*/

#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <utility>
#include <set>
using namespace std;

void topoSort(vector<vector<int> > &arr,vector<char> &topo_sort,int n)
{
    // I will create an indegree array
    vector<int> indegree(n,0);

    for(int i=0;i<n;i++)
    {
        for(auto &nodes:arr[i])
        indegree[nodes]++;
    }

    //Now I will push all the nodes with indegree 0 into a queue
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }

    while (!q.empty())
    {
        int node=q.front();
        q.pop();

        topo_sort.push_back(node+'a');

        for(auto &neighbour:arr[node])
        {
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            q.push(neighbour);
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<string> arr(n);

    for(int i=0;i<n;i++)
    cin>>arr[i];

    //since I have k starting alphabhets , so we will create a graph for k nodes

    vector<vector<int> >v(k);

    // I will create the graph first from the sorted dictionary

    for(int i=0;i<n-1;i++)
    {
        string s1=arr[i];
        int l1=s1.length();
        string s2=arr[i+1];
        int l2=s2.length();

        int j=0;

        while(j<l1 && j<l2)
        {
            if(s1[j]!=s2[j])
            {
                //the moment where two letters didn't match , I will create a graph
                v[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
            j++;
        }
    }

    vector<char> topo_sort;
    
    topoSort(v,topo_sort,k);

    for(auto &letters:topo_sort)
    cout<<letters<<" ";
}