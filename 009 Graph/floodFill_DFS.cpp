// Context : https://youtu.be/C-2_uSRli8o?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// GFG link : https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

/*
A good test case : 

8 5
2 3 2 1 2
3 3 3 3 1
3 1 1 1 2
1 2 2 1 3
1 2 3 3 1
2 1 2 2 2
1 2 2 1 1
3 1 1 1 2
4 0 1

Here we have got to replace 1 with 1 only 

*/

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

void dfs(vector<vector<int>> &arr, int i, int j, int r, int c, int new_value, int orig_val)
{
    // first we will check if we are inside array

    if (i < 0 || j < 0 || i >= r || j >= c || arr[i][j] != orig_val)
        return;
    else
    {
        // change the pixel value
        arr[i][j] = new_value;

        // dfs towards all four directions

        // left
        dfs(arr, i, j - 1, r, c, new_value, orig_val);
        // right
        dfs(arr, i, j + 1, r, c, new_value, orig_val);
        // up
        dfs(arr, i - 1, j, r, c, new_value, orig_val);
        // down
        dfs(arr, i + 1, j, r, c, new_value, orig_val);
    }
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

    int start_i, start_j, new_value;
    cin >> start_i >> start_j >> new_value;

    int orig_value = arr[start_i][start_j];

    if (orig_value == new_value)
    {
        //Now you must be thinking why did I do this condition check ......
        /*
        so if we get to replace a pixel with same value then , it will result in same image 
        and since we are not using any visited array to keep track of cells visited separately , so we will end in Infinite recusrio
        Basically : stack over flow , segmentation fault.....

        A sample test case has been shown above
        */
        print(arr, r, c);
    }
    else
    {
        dfs(arr, start_i, start_j, r, c, new_value, arr[start_i][start_j]);

        print(arr, r, c);
    }
}