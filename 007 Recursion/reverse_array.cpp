//Reverse an array using recursion

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<unordered_map>
#include<set>
#include<map>
#include<unordered_set>
#include<string>
#include<limits.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;

void reverseArray(int arr[],int n,int i)
{
    if(i>=n/2)
    return;

    swap(arr[i],arr[n-i-1]);
    reverseArray(arr,n,i+1);
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<"\n\n";
}

int main()
{
    int arr1[]={1,2,3,4,5};
    int arr2[]={1,2,3,4,5,6};

    reverseArray(arr1,5,0);
    reverseArray(arr2,6,0);

    printArray(arr1,5);
    printArray(arr2,6);

}