//Context : https://youtu.be/DREutrv2XD0?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Proble link : https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

// Prerequisite : https://github.com/anandsagar00/Advanced-Data-Structures/blob/main/009%20Graph/word_ladder_1_Brute_BFS.cpp

/*
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths.
Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
*/

/*
5
cccc
caab
aacc
baca
abca
cbcb
baca
*/

/*
Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
*/


#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<algorithm>
#include<map>
#include<unordered_map>
#include <utility>
#include <set>
using namespace std;

//This is a brute force approach and yet it passes all the TCs on GFG

vector<vector<string> > wordLadder(string &startWord, string &targetWord, vector<string> &wordList)
{
    //First I'll create an unordered_map of wordList so that it gives me O(1) acces time 
   // I will be using this unordered map also to check if I have visited it or not
    
    unordered_map<string,int> ump;

    //this loop will insert each word into ump with 0 as value , this time I'll not be using this as visited
    // instead I will be checking inside sequence array only for visited 
    for(auto &it:wordList)
    ump[it]++;

    //This will store the answer
    vector<vector<string> > ans;

    // This time the queue will be different , instead of storing one string and step , we will store list of string

    queue<vector<string> > q;

    vector<string> temp;
    temp.push_back(startWord);
    
    q.push(temp);

    while(!q.empty())
    {
        vector<string> sequence=q.front();
        q.pop();

        string last_word=sequence.back();

        //if the last word is the target word then we will push sequence to ans
        if(last_word==targetWord)
        {
            if(ans.size()==0)
            ans.push_back(sequence);
            else if(ans.size()!=0 && ans[0].size()==sequence.size())
            {
                ans.push_back(sequence);
            }
            continue; //continuing as the first one we meet will be smallest and we don't need further processing on that
        }

        // I will try to change each letter at each index from 'a' - 'z' and will push it to the queue
       // only if it is present in the ump and has not been visited yet

        for(int i=0;i<last_word.length();i++)
        {
            char orig_ch=last_word[i];//this is storing the original char
            for(char j='a';j<='z';j++)
            {
                last_word[i]=j;
                //this is checking if last word is there in word list and it is not in current sequence
                if(ump[last_word] && (sequence.empty()||find(sequence.begin(),sequence.end(),last_word)==sequence.end()))
                {
                    sequence.push_back(last_word);
                    q.push(sequence); //inserting sequence into queue and popping back for next use
                    sequence.pop_back();
                }
            }
            last_word[i]=orig_ch;//I am putting back the original character , so that next letters can be replaced , without affecting the previous letters
        }
    }
    return ans;
}

int main()
{
    int n;
    vector<string> word_list(n);
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>word_list[i];
    }
    string start_word,target_word;
    cin>>start_word>>target_word;
    
    vector<vector<string> > ans=wordLadder(start_word,target_word,word_list);

    for(auto &v:ans)
    {
        for(auto &nums:v)
        cout<<nums<<" ";
        cout<<"\n";
    }
}