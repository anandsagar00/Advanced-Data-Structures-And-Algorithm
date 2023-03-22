// Context : https://youtu.be/eQCS_v3bw0Q?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// Print sub-sequence with sum k , the input array can have negative numbers as well

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<set>
using namespace std;

void printSubSumK(vector<int> &arr,int k,int i, int curr_sum,vector<int> &temp)
{
    //if we reach the end of the array 
    if(i>=arr.size())
    {
        if(curr_sum==k)
        {
            for(auto &it:temp)
            cout<<it<<" ";
            cout<<"\n";
        }
        return;
    }
    else
    {
        //Case 1 : don't current element
        printSubSumK(arr,k,i+1,curr_sum,temp);

        //case 2 : take the current element
        temp.push_back(arr[i]);
        printSubSumK(arr,k,i+1,curr_sum+arr[i],temp);
        temp.pop_back();
    }
}

int main()
{
    int array[]={1,2,3,4,5,0,-1,1,-2,2};
    vector<int> arr(array,array+10);
    vector<int> temp;
    printSubSumK(arr,5,0,0,temp);

}
