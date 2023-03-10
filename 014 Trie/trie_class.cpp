// Article : https://www.javatpoint.com/trie-data-structure

// Video : https://youtu.be/dBGUmUQhjaM?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp

/*
The word "Trie" is an except from the word "retrieval".
Trie is a sorted tree-based data-structure that stores the set of strings.
It has the number of pointers equal to the number of characters of the alphabet in each node.
It can search a word in the dictionary with the help of the word's prefix.
For example, if we assume that all strings are formed from the letters 'a' to 'z' in the English alphabet,
each trie node can have a maximum of 26 points.

Trie is also known as the digital tree or prefix tree. The position of a node in the Trie determines the key with which that node is connected.

Properties of the Trie for a set of the string:
The root node of the trie always represents the null node.
Each child of nodes is sorted alphabetically.
Each node can have a maximum of 26 children (A to Z).
Each node (except the root) can store one letter of the alphabet.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Trie
{
    vector<Trie *> children;
    bool end_of_word;
    public:
    Trie()
    {
        //Default constructor to initialise all required variables
        children.resize(26,NULL);
        end_of_word=true;
    }

    //recursive function to insert string into Trie
    void insert(string str,Trie *trie,int i=0)
    {
        //If it is the end of the word to insert and there is no other word with same prefix
        if(i==str.size())
        {
            return;
        }
        else
        {
            //inserting the current character and calling to insert for next characters

            //First I will mark this as not end of word as there is a character
            trie->end_of_word=false;

            //Initialising the children ensures that there may be more words with same prefix

            //If children are null , that means this is the first time this character is being inserted on this path
            if(!trie->children[str[i]-'a'])
            {
                trie->children[str[i]-'a']=new Trie();
                insert(str,trie->children[str[i]-'a'],i+1);
            }

            //other wise it means that there is already a word with same prefix till now
            else
            {
                insert(str,trie->children[str[i]-'a'],i+1);
            }

        }
    }

    void printAllWords(Trie *trie,string temp="")
    {
        cout<<temp<<"\n";
        if(trie==NULL || trie->end_of_word)
        {
            return;
        }
        else
        {
            for(int i=0;i<26;i++)
            {
                if(trie->children[i])
                {
                    temp.push_back('a'+i);
                    printAllWords(trie->children[i],temp);
                    temp.pop_back();//after the call finishes back-track
                }
            }
        }
    }

    //This function will search is a word is present in Trie or not , i.e. if any word begins with given word or not
    bool search(Trie *trie,string key_word,int i=0)
    {
        if(trie==NULL || trie->end_of_word==true)
        return false;
        else if(i==key_word.size()-1)
        {
            //if it is the last character of the word to search , then we will check if children at that character_index exists or not
            if(trie->children[key_word[i]-'a']!=NULL)
            return true;
            else
            return false;
        }
        else
        {
            //I will be forming the word by adding one character at a time
            int character_index=key_word[i]-'a'; // this will give the result in range of 0-26
            return search(trie->children[character_index],key_word,i+1);
        }
    }
};

int main()
{
    Trie *trie=new Trie();
    trie->insert("hello",trie);
    trie->insert("hell",trie);
    trie->insert("help",trie);
    trie->insert("apple",trie);
    trie->insert("apps",trie);

    cout<<"\nWords which can be formed in the trie are : \n";
    trie->printAllWords(trie);

    //I am searching words he , heelo , helo , hellox , hello , app ,aaply
    cout<<"\nSearch Result : \n";
    cout<<trie->search(trie,"he")<<"\n";
    cout<<trie->search(trie,"heelo")<<"\n";
    cout<<trie->search(trie,"helo")<<"\n";
    cout<<trie->search(trie,"hellox")<<"\n";
    cout<<trie->search(trie,"hello")<<"\n";
    cout<<trie->search(trie,"app")<<"\n";
    cout<<trie->search(trie,"apply")<<"\n";
    cout<<trie->search(trie,"a")<<"\n";
}