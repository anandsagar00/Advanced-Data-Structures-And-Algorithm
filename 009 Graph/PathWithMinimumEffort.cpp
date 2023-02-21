// Context : https://youtu.be/0ytpZyiZFhA?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1

/*
You are a hiker preparing for an upcoming hike.
You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col).
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
*/

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

// [Note : This is Dijkstra algorithm for 2d matrix , this stores the abs diff b/w two adj nodes]

int MinimumEffort(vector<vector<int>>& arr)
{
    int n=arr.size();
    int m=arr[0].size();

    //this will make a min PQ , which can store vectors
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int> > > pq;

    //creating a distance array and storing INFINITY (very large value) 
    vector<vector<int> > distance(n,vector<int>(m,9999999));

    distance[0][0]=0;

    //the vector in PQ will contain 3 things {abs diff , row coord , col coord}
    pq.push({0,0,0});

    while(!pq.empty())
    {
        vector<int> detail=pq.top();
        pq.pop();

        int abs_diff=detail[0];
        int x=detail[1];
        int y=detail[2];

        //Left , Right , Up , Down
        vector<vector<int> > directions={{0,-1},{0,1},{-1,0},{1,0}};

        for(auto &direction:directions)
        {
            //first we will check we are inside grid
            int new_x=x+direction[0];
            int new_y=y+direction[1];

            if(new_x>=0 && new_x<n && new_y>=0 && new_y<m )
            {
                int new_effort=max(abs_diff,abs(arr[x][y]-arr[new_x][new_y]));

                if(new_effort<distance[new_x][new_y])
                {
                    distance[new_x][new_y]=new_effort;
                    pq.push({new_effort,new_x,new_y});
                }
            }
        }
    }
    return distance[n-1][m-1];  
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int> > arr(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
}