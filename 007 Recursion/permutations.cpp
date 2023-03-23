// Video : https://youtu.be/YK78FU5Ffjw?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

//LeetCode Proble Link : https://leetcode.com/problems/permutations/

class Solution {
public:
    
    //I will be using DFS like approach where in I will not be considering element already in solution
    void permute(vector<int>& nums,vector<int> &visited,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                temp.push_back(nums[i]);
                permute(nums,visited,temp,ans);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<int> visited(nums.size(),0);
        vector<vector<int>> ans;
        permute(nums,visited,temp,ans);
        return ans;
    }
};