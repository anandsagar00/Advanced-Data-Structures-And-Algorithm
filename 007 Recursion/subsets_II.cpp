// Video : https://youtu.be/RIn3gOkbhQE?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// Problem Link : https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    
    void subsetsWithDup(vector<int>& nums,int i,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(i>=nums.size())
            ans.push_back(temp);
        else
        {
            //If I don't take an element then I won't take any of it's copies also
            int temp_i=i;
            
            while(temp_i<nums.size() && nums[i]==nums[temp_i])
                temp_i++;
            
            // Case 1 : Don't take element into consideration
            
            subsetsWithDup(nums,temp_i,ans,temp);
            
            //Case 2 : take current element into consideraion
            temp.push_back(nums[i]);
            subsetsWithDup(nums,i+1,ans,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        subsetsWithDup(nums,0,ans,temp);
        return ans;
    }
};