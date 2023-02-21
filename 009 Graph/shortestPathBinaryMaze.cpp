// Context : https://youtu.be/U5Mw4eyUmw4?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem : https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int shortestPath(vector<vector<int> > &arr, pair<int, int> src,pair<int, int> dest)
{
    int i=src.first,j=src.second,k=dest.first,l=dest.second;

    int n=arr.size();
    int m=arr[0].size();

    //If either starting or ending pt is 0 then no path exist , as we can move only on 1s
    if(arr[i][j]==0 || arr[k][l]==0)
    return -1;

    //In this I will be storing Coordinates in 0th and 1th cell if vector and steps in 3rd cell
    queue<vector<int> > q;

    q.push({i,j,0});//inserting source coordinates as well as steps
    arr[i][j]=0;//marking as visited
    while(!q.empty())
    {
        vector<int> detail=q.front();
        q.pop();

        int x=detail[0],y=detail[1],steps=detail[2];

        if(x==k && y==l)
        {
            return steps;
        }

        //Left , Right , Up , Down
        vector<vector<int> > directions={{0,-1},{0,1},{-1,0},{1,0}};

        for(auto &direction:directions)
        {
            //first we will check we are inside grid
            int new_x=x+direction[0];
            int new_y=y+direction[1];

            if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && arr[new_x][new_y]==1)
            {
                arr[new_x][new_y]=0;//marking as visited
                q.push({new_x,new_y,steps+1});
            }
        }
    }
    return -1;
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

    pair<int,int> src,dest;
    cin>>src.first>>src.second>>dest.first>>dest.second;

    cout<<shortestPath(arr,src,dest);
}