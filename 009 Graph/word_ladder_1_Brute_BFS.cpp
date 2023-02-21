// Context : https://youtu.be/tRPda0rcf8E?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn

// Problem link : https://practice.geeksforgeeks.org/problems/word-ladder/1

/*
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths.
Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0
*/

/*
Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".
*/

#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include<unordered_map>
#include <utility>
#include <set>
using namespace std;

//This is a brute force approach and yet it passes all the TCs on GFG

int wordLadderLength(string &startWord, string &targetWord, vector<string> &wordList)
{
    //First I'll create an unordered_map of wordList so that it gives me O(1) acces time 
   // I will be using this unordered map also to check if I have visited it or not
    
    unordered_map<string,int> ump;

    //this loop will insert each word into ump with 0 as value , I'll be updating this 0 to 1 for visited
    for(auto &it:wordList)
    ump[it]=0;

    //I will be storing the strings formed along with level / or steps 
    queue<pair<string,int> > q;

    q.push(make_pair(startWord,1));

    if(ump.find(startWord)!=ump.end())
    ump[startWord]=1;


    while (!q.empty())
    {
        string word=q.front().first;
        int step=q.front().second;
        q.pop();

        /*
        The code can further be optimised , instead of returning from here 
        I can return the moment word is formed as target word
        */
        if(word==targetWord)
        return step;

        // I will try to change each letter at each index from 'a' - 'z' and will push it to the queue
       //  if it is present in the ump and has not been visited yet

        for(int i=0;i<word.length();i++)
        {
            char orig_ch=word[i];//this is storing the original char
            for(char j='a';j<='z';j++)
            {
                word[i]=j;
                if(ump.find(word)!=ump.end() && ump[word]==0)
                {
                    ump[word]=1;
                    q.push(make_pair(word,step+1));
                }
            }
            word[i]=orig_ch;//I am putting back the original character , so that next letters can be replaced , without affecting the previous letters
        }
    }
    return 0;
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
    cout<<wordLadderLength(start_word,target_word,word_list);
}