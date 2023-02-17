// Context : https://youtu.be/BtdgAys4yMk?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

//Problem link : https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs

/*
Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X at locations just below,
just above, just left and just right of it.
*/


#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

void DFS(vector<vector<char> > &arr,vector<vector<char> > &ans,int i,int j,int r,int c)
{
    if(i<0 || j<0 || i>=r || j>=c || arr[i][j]!='O')
    return;

    //I will be using another letter like 'V' to mark that I've visited that cell
    arr[i][j]='V';
    ans[i][j]='O';

    //now I will be calling DFS in all four direction

    //left
    DFS(arr,ans,i,j-1,r,c);
    //right
    DFS(arr,ans,i,j+1,r,c);
    //up
    DFS(arr,ans,i-1,j,r,c);
    //down
    DFS(arr,ans,i+1,j,r,c);
}

void print(vector<vector<char> > &arr)
{
    for(auto &vectors:arr)
    {
        for(auto &letters:vectors)
        cout<<letters<<" ";
        cout<<"\n";
    }
}

int main()
{
    int r,c;
    cin>>r>>c;

    vector<vector<char> > arr(r,vector<char>(c,'O'));

    //taking input in the 2d array/vector
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cin>>arr[i][j];
    }

    /*
    I'll create a separate array filled with X and
    I will be starting DFS from all the boundary O's and we will be marking all the O's I meet in DFS
    in the new array
    */

   /*
   There is an alternate approach also , create a visited array and start doing DFS from boundary O's only
   and at last mark all un-visited cells in visited array as X 
   */

    vector<vector<char> > ans(r,vector<char>(c,'X'));

    //Now I will be traversing on all four boundaries 

    //Left boundary
    for(int i=0;i<r;i++)
    {
        if(arr[i][0]=='O')
        {
            DFS(arr,ans,i,0,r,c);
        }
    }
    //Right boundary
    for(int i=0;i<r;i++)
    {
        if(arr[i][c-1]=='O')
        {
            DFS(arr,ans,i,c-1,r,c);
        }
    }
    //Top boundary
    for(int i=0;i<c;i++)
    {
        if(arr[0][i]=='O')
        {
            DFS(arr,ans,0,i,r,c);
        }
    }
    //Bottom boundary
    for(int i=0;i<c;i++)
    {
        if(arr[r-1][i]=='O')
        {
            DFS(arr,ans,r-1,i,r,c);
        }
    }
    cout<<"\n";
    print(ans);
}