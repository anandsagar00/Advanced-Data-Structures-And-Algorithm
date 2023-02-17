// Context : https://youtu.be/rxKcepXQgU4?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

void DFS(vector<vector<int> > &arr,int i,int j,int r,int c,int &count)
{
    if(i<0 || j<0 || i>=r || j>=c || arr[i][j]!=1)
    return;

    //I will be using another integer like 0 to mark that I've visited that cell
    arr[i][j]=0;
    count+=1;

    //now I will be calling DFS in all four direction

    //left
    DFS(arr,i,j-1,r,c,count);
    //right
    DFS(arr,i,j+1,r,c,count);
    //up
    DFS(arr,i-1,j,r,c,count);
    //down
    DFS(arr,i+1,j,r,c,count);
}


int main()
{
    int r,c;
    cin>>r>>c;

    vector<vector<int> > arr(r,vector<int>(c,'O'));

    //taking input in the 2d array/vector
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cin>>arr[i][j];
    }

    /*
    This problem is very similar to Surrounded Regions problem https://github.com/anandsagar00/Advanced-Data-Structures/blob/main/009%20Graph/surroundedRegions.cpp

    So we will count the number of 1's through which we can go out , and we will subtract it from total 1's

    Now , we can only go out of grid from boundary 1's and the 1's which are connected to that

    so....

    if we start DFS from that then we can count number of 1's through which we can move out.

    This method also passes all the Test Cases on GFG
    */

   //counting the total number of 1's in grid
   int total=0;
   for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        total+=arr[i][j];
    }

    //Now I'll be doing DFS from all four boundaries , and I'll be modifying the original grid itself

    //Now I will be traversing on all four boundaries 

    int count=0;
    //Left boundary
    for(int i=0;i<r;i++)
    {
        if(arr[i][0]==1)
        {
            DFS(arr,i,0,r,c,count);
        }
    }
    //Right boundary
    for(int i=0;i<r;i++)
    {
        if(arr[i][c-1]==1)
        {
            DFS(arr,i,c-1,r,c,count);
        }
    }
    //Top boundary
    for(int i=0;i<c;i++)
    {
        if(arr[0][i]==1)
        {
            DFS(arr,0,i,r,c,count);
        }
    }
    //Bottom boundary
    for(int i=0;i<c;i++)
    {
        if(arr[r-1][i]==1)
        {
            DFS(arr,r-1,i,r,c,count);
        }
    }

    cout<<total-count<<"\n";
}