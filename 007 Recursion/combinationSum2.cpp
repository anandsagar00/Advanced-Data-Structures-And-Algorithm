// Video : https://youtu.be/G1fRTGRxXU8?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// LeetCode : https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    
    void combinationSum(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp,int i) {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        else if(i>=candidates.size() || target<0)
            return;
        else
        {
            //Two cases 
            
            //Case 1 don't take the element and also don't take it's copies or duplicates
            int temp_i=i;
            while(temp_i<candidates.size() && candidates[temp_i]==candidates[i])
                temp_i++;
            combinationSum(candidates,target,ans,temp,temp_i);
            
            //Case 2 take element into consideration 
            temp.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],ans,temp,i+1);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        //sorting so that all same element come together 
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(candidates,target,ans,temp,0);
        return ans;
    }
};