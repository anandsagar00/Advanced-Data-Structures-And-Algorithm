// Video : https://youtu.be/bLGZhJlt4y0?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

//Question Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    void rat(vector<vector<int>> arr,int n,int i,int j,string s,vector<string> &v)
    {
        if(i==n-1 && j==n-1 && arr[i][j]==0)
        return;
        if(i<0 || j<0 || i>=n||j>=n||arr[i][j]==0 || arr[i][j]==-1)
        return;
        if(i==n-1 && j==n-1)
        {
            v.push_back(s);
            return;
        }
        arr[i][j]=-1;
        //down
        rat(arr,n,i+1,j,s+"D",v);
        //left
        rat(arr,n,i,j-1,s+"L",v);
         //right
        rat(arr,n,i,j+1,s+"R",v);
        //up
        rat(arr,n,i-1,j,s+"U",v);
        arr[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        vector<string> vect;
        rat(arr,n,0,0,"",vect);
        return vect;
    }
};

    
