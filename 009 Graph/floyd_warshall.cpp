// Context : https://youtu.be/YbY8cVwWAvw?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
// Practice Link : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
/*
Go via every vertex/node ,ex : If I have 5 nodes and I have to go to node 2 from 0 , so I'll try all of the below paths

0->1->2
0->2->2 ... which is 0->2
0->3->2
0->4->2

[ALL PAIR SHORTEST PATH ALG]

Also helps us in detecting NEGATIVE CYCLES
*/

// We will use ADJ MAT to stote the graph

#include<iostream>
#include<vector>

using namespace std;

#define INFINITY 9999999

void floydWarshall(int **arr,int n)
{
    vector<vector<int> > distance(n,vector<int>(n));

    //We will initialise the distance matrix same as the ADJ MAT

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        distance[i][j]=arr[i][j];
    }

    for(int i=0;i<n;i++)//this loop marks the source node
    {
        for(int j=0;j<n;j++)//this will be the dest node
        {
            for(int k=0;k<n;k++)//this is intermediate node
            {
                //by this we make sure that we choose min of already existing path and path via intermediate node
                distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }

    bool negWtCycle=false;

    //If the path from node to itself is not 0 (NEGATIVE) then there is negative wt cycle , as in cycle only it is goin to reduce

    for(int i=0;i<n;i++)
    {
        if(distance[i][i]<0)
        {
            negWtCycle=true;
            break;
        }
    }
    if(!negWtCycle){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<distance[i][j]<<" ";
        }
        cout<<"\n";
    }
    }
    else
    cout<<"NEGATIVE WT CYCLE EXISTS IN GRAPH.\n";

}

int main()
{
    int n;//the number of nodes
    cin>>n;

    //I will be creating a Double Dimensional Array completely in heap
    //This will make things easy for us , passing a DDA as double pointer is very simple
    int **arr; 
    arr=new int*[n];

    for(int i=0;i<n;i++)
    arr[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }
    floydWarshall(arr,n);
}
