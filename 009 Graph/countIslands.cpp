// Context : https://youtu.be/muncqlKJrH0?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

/*
Here we will be getting a 2-d array as input , which will be having 0s and 1s only
We have to return the count of total islands.....you can read more about the problem here

https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/
*/
#include<iostream>
#include<vector>
using namespace std;

void DFS(int i,int j,int r,int c,vector<vector<int> > &arr)
{
    //fist we will check if we are inside the grid and on unvisited cell , if not return
    if(i<0 || i>=r || j<0||j>=c || arr[i][j]==0)
    return;
    else 
    {
        arr[i][j]=0; // We will not be using Visited array instead we will mark by
                    // turning 1 into 0 , so that we don't go on that cell again
        
        //Now we will go in all 8 directions up,down,left,right,Upper-left-diag....and so on

        DFS(i-1,j,r,c,arr);//up
        DFS(i+1,j,r,c,arr);//down
        DFS(i,j-1,r,c,arr);//left
        DFS(i,j+1,r,c,arr);//right
        DFS(i-1,j-1,r,c,arr);//upper left diagonal
        DFS(i-1,j+1,r,c,arr);//upper right diagonal
        DFS(i+1,j-1,r,c,arr);//lower left diagonal
        DFS(i+1,j+1,r,c,arr);//lower right diagonal
    }
}

int main()
{
    int r,c;
    cin>>r>>c;

    vector<vector<int> > arr(r,vector<int>(c,0));

    //taking input in the 2d array/vector
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cin>>arr[i][j];
    }

    int count=0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            //if it is unvisited and is land then perform DFS
            if(arr[i][j]==1)
            {
                DFS(i,j,r,c,arr);
                count++;
            }
        }
    }
    cout<<count<<"\n";
}