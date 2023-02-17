// Context : https://youtu.be/7zmgQSJghpo?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

//INTERESTING QUESTION , as Shape of island matters in this question

//Soln : Store the shape in a set like R for right , D for down , L for left , and U for Up

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<set>
using namespace std;

/*
This function doesn't get all TCs passed where as other one gets all TCs passed
I've not yet been able to find out the reason , both the functions are more or less similar only
*/
void DFS(vector<vector<int> > &arr,int i,int j,string &path_taken,char direction)
{
    //I have used a direction variable to tell in next step from which dir I am coming
    //Since I am having a variable path_taken by reference 
    int r=arr.size();
    int c=arr[0].size();

    //Here I am modifying the same array and using 0 to mark that I've visited, since I will be travesing only 1's
    if(i<0 || j<0 || i>=r || j>=c || arr[i][j]==0)
    return;
    else
    {
        arr[i][j]=0;

        path_taken.push_back(direction);

        //perform DFS in all 4 directions
        
        //Left
        DFS(arr,i,j-1,path_taken,'L');

        //Right
        DFS(arr,i,j+1,path_taken,'R');

        //Up
        DFS(arr,i-1,j,path_taken,'U');

        //Down
        DFS(arr,i+1,j,path_taken,'D');
        
    }
}


string DFS(vector<vector<int> > &arr,int i,int j)
{
    //I have used a direction variable to tell in next step from which dir I am coming
    //Since I am having a variable path_taken by reference 
    int r=arr.size();
    int c=arr[0].size();

    //Here I am modifying the same array and using 0 to mark that I've visited, since I will be travesing only 1's
    if(i<0 || j<0 || i>=r || j>=c || arr[i][j]==0)
    return "";
    else
    {
        arr[i][j]=0;

        string s="";

        //perform DFS in all 4 directions
        
        //Left
        s=s+"L"+DFS(arr,i,j-1);

        //Right
        s=s+"R"+DFS(arr,i,j+1);

        //Up
        s=s+"U"+DFS(arr,i-1,j);

        //Down
        s=s+"D"+DFS(arr,i+1,j);
        return s;
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
    
    set<string> st;//to store unique shapes

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==1)
            {
                st.insert(DFS(arr,i,j));
            }
        }
    }
    cout<<st.size()<<"\n";
}
