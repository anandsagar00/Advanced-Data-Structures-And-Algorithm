// Context : https://youtu.be/edXdVwkYHF8?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, 
where i1, j1 are the row number and column number of the current cell, 
and i2, j2 are the row number and column number of the nearest cell having value 1.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

vector<vector<int> > nearest(vector<vector<int> > &arr)
{
    int r=arr.size();
    int c=arr[0].size();

    //I'll be storing answer in this vector
    vector<vector<int> > ans(r,vector<int>(c,0));

    vector<vector<int> > visited(r,vector<int>(c,0));

    //first we will take out the details of coordinates of the 1's in the queue and number of steps it has moved in BFS
    queue<pair<pair<int,int>,int > > q;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==1)
            {
                q.push(make_pair(make_pair(i,j),0));
            }
        }
    }

    while(!q.empty())
    {
        int i=q.front().first.first;
        int j=q.front().first.second;

        int steps=q.front().second;

        q.pop();

        // we will travel in all 4 directions and as soon as we will find 1 we will add the dist to answer vector
        
        //left
        if(j-1>=0 && visited[i][j-1]==0 && arr[i][j-1]==0)
        {
            //inserting into answer
            ans[i][j-1]=steps+1;
            //inserting into queue
            q.push(make_pair(make_pair(i,j-1),steps+1));
            //marking as visited
            visited[i][j-1]=1;
            
        }

        //right
        if(j+1<c && visited[i][j+1]==0 && arr[i][j+1]==0)
        {
            //inserting into answer
            ans[i][j+1]=steps+1;
            //inserting into queue
            q.push(make_pair(make_pair(i,j+1),steps+1));
            //marking as visited
            visited[i][j+1]=1;
            
        }

        //down

        if(i+1<r && visited[i+1][j]==0 && arr[i+1][j]==0)
        {
            //inserting into answer
            ans[i+1][j]=steps+1;
            //inserting into queue
            q.push(make_pair(make_pair(i+1,j),steps+1));
            //marking as visited
            visited[i+1][j]=1;
        }

        //Up
        if(i-1>=0 && visited[i-1][j]==0 && arr[i-1][j]==0)
        {
            //inserting into answer
            ans[i-1][j]=steps+1;
            //inserting into queue
            q.push(make_pair(make_pair(i-1,j),steps+1));
            //marking as visited
            visited[i-1][j]=1; 
        }
    }
    return ans;
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

    
}