// Context : https://youtu.be/ogjf7ORKfd8?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// Merge-Sort

#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

void merge(int arr[],int start,int end)
{
    //This function will merge the two sorted halves of the array into one

    int n=(end-start)+1; // this variable keeps track of how many elements we have to merge now

    int mid=(start+end)/2;

    int i=start;
    int j=mid+1;
    int k=0;

    int ans[n];//to store the ans;

    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            ans[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            ans[k]=arr[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        ans[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        ans[k]=arr[j];
        j++;
        k++;
    }

    for(int i=0;i<n;i++)
    {
        arr[start+i]=ans[i];
    }
}

void mergeSort(int arr[],int low,int high,int n)
{
    if(low>=high)
    return;

    int mid=(low+high)/2;
    mergeSort(arr,low,mid,n);
    mergeSort(arr,mid+1,high,n);
    merge(arr,low,high);
}

int main()
{
    int arr[]={23,435,-32,238,0,45,-347,47,245,34,45998,237};
    mergeSort(arr,0,11,12);

    for(int i=0;i<12;i++)
    cout<<arr[i]<<" ";
}