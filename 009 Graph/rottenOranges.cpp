// Context : https://youtu.be/yf3oUhkvqA0?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges.
A rotten orange at index [i,j] can rot other fresh orange at indexes 
                                    [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) 
                                                in unit time. 
*/

// I've tried a little different method from Striver's video , you can try that as well

#include <iostream>
#include <vector>
#include<queue>
#include<utility>
using namespace std;

//this is a simple BFS approach

int calculateTime(vector<vector<int>> &arr,int r,int c)
{
    //We will be pushing the coordinates of all the rotten oranges in this queue first.....as
   //when time t=0 all rotten oranges present will start rotting others all at once
    queue<pair<int,int> > q;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==2)
            q.push(make_pair(i,j));
        }
    }

    int time=0;

    while(!q.empty())
    {
        bool flag=false; // to indicate that at least in this iteration we found a fresh orange which we can rot

        int s=q.size();
        for(int k=0;k<s;k++)
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            /*
            I am marking the fresh orange here itself as rotten in if condition only , because a chance may arise that the
            same fresh orange is put twice in the queue
            */
            //top
            if(i-1>=0 && arr[i-1][j]==1)
            {
                arr[i-1][j]=2;
                q.push({i-1,j});
                flag=true;
            }
            //down
            if(i+1<r && arr[i+1][j]==1)
            {
                arr[i+1][j]=2;
                q.push({i+1,j});
                flag=true;
            }
            //left
            if(j-1>=0 && arr[i][j-1]==1)
            {
                arr[i][j-1]=2;
                q.push({i,j-1});
                flag=true;
            }
            //right
            if(j+1<c && arr[i][j+1]==1)
            {
                arr[i][j+1]=2;
                q.push({i,j+1});
                flag=true;
            }
        }
        if(flag)
        time++;
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==1)
            {
                //if there are still fresh oranges then return -1
                return -1;
            }
        }
    }
    return time; 
}

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> arr(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];
    }

    
}