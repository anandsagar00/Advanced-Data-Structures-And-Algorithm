// Context : https://youtu.be/muncqlKJrH0?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

/*
Here we will be getting a 2-d array as input , which will be having 0s and 1s only
We have to return the count of total islands.....you can read more about the problem here

https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/
*/
#include<iostream>
#include<vector>
using namespace std;



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