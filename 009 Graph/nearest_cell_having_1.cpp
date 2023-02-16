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

//TODO : Write algorithm

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