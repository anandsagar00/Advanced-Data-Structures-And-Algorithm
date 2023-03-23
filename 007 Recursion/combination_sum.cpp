// Context : https://youtu.be/OyZFFqQtu98?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// Problem Link : https://leetcode.com/problems/combination-sum/submissions/

//This is direct LeetCode solution of the problem

class Solution {
public:
    
    void combinationSum(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp,int i) {
        if(i>=candidates.size() || target<0)
            return;
        else if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        else
        {
            //Two cases 
            
            //Case 1 don't take the element
            combinationSum(candidates,target,ans,temp,i+1);
            
            //Case 2 take element into consideration 
            temp.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],ans,temp,i);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(candidates,target,ans,temp,0);
        return ans;
    }
};