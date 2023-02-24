// Context : https://youtu.be/YbY8cVwWAvw?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
// Practice Link : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
/*
Go via every vertex/node ,ex : If I have 5 nodes and I have to go to node 2 from 0 , so I'll try all of the below paths

0->1->2
0->2->2 ... which is 0->2
0->3->2
0->4->2

[ALL PAIR SHORTEST PATH ALG] , [CAN WORK FOR BOTH DIRECTED AND UNDIRECTED GRAPH]

Also helps us in detecting NEGATIVE CYCLES
*/

// We will use ADJ MAT to stote the graph

#include<iostream>
#include<vector>

using namespace std;

#define INFINITY 9999999

void floydWarshall(int **arr,int n)
{
    vector<vector<int> > distance(n,vector<int>(n,INFINITY));

    //We will initialise the distance matrix same as the ADJ MAT

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0 && i!=j)
            {
                //nodes unreachable
                distance[i][j]=INFINITY;
            }
            else if(arr[i][j]==0 && i==j)
            {
                distance[i][j]=0;
            }
            else
            distance[i][j]=arr[i][j];
        }
    }
    /*
    The reason intermediate node loop is outside is that , if we keep it inside then we will use the wrong values of
    intermediate node , i.e. the intermediate nodes would not be calculated and we would still be using it in our solution
    */
    for(int k=0;k<n;k++)//This is loop for intermediate node
    {
        for(int i=0;i<n;i++)//This is loop for source node
        {
            for(int j=0;j<n;j++)//this is loop for dest node
            {
                // We are trying to find shortest path from i to j via k (i.e. i->k->j)

                if(distance[i][k]==INFINITY || distance[k][j]==INFINITY)
                continue;
                else
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

    int edg;
    cin>>edg;

    for(int i=0;i<edg;i++)
    {
        // I have taken example of UNDIRECTED GRAPH , you can modify this for DIRECTED as well
        int u,v,w;
        cin>>u>>v>>w;
        arr[u][v]=w;
        arr[v][u]=w;
    }

    floydWarshall(arr,n);
}
