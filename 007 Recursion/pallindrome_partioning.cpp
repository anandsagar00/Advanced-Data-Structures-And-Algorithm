// Video : https://youtu.be/WBgsABoClE0?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// Problem Link : https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    
    bool isPallindrome(string str)
    {
        int n=str.size();
        for(int i=0;i<n/2;i++)
        {
            if(str[i]!=str[n-i-1])
                return false;
        }
        return true;
    }
    
    void partition(string s,vector<string> &temp,vector<vector<string>> &ans)
    {
        if(s.size()==0)
        {
            ans.push_back(temp);
            return;
        }
        else
        {
            int n=s.size();
            for(int i=1;i<=n;i++)
            {
                string left_partition=s.substr(0,i);
                if(isPallindrome(left_partition))
                {
                    temp.push_back(left_partition);
                    string right_partition=s.substr(i);
                    partition(right_partition,temp,ans);
                    temp.pop_back();
                }
                
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partition(s,temp,ans);
        return ans;
    }
};