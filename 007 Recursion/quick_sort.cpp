// Context : https://youtu.be/WIrA4YexLRQ?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

// Quick - Sort : https://takeuforward.org/data-structure/quick-sort-algorithm/

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

/*
The algorithm is very simple choose an element (pivot element) place it at it's correct position 
once the element is placed at it's correct position do the same for left and right arrays
*/

void quickSort(int arr[],int low,int high)
{
    if(low>=high)
    return;
    else
    {
        int pivot=arr[low];
        int i=low;
        int j=high;

        while(i<j)
        {
            while(i<=high && arr[i]<=pivot)
            i++;

            while(j>=low && arr[j]>pivot)
            j--;

            if(i<j)
            swap(arr[i],arr[j]);
            
        }

        //the moment i crosses j , it is the partition index i.e. it is the correct place for pivot element
        
        int partition_index=j;

        //Here we place PIVOT element at correct place
        swap(arr[low],arr[partition_index]);

        quickSort(arr,low,partition_index-1);
        quickSort(arr,partition_index+1,high);

    }
}

int main()
{
    int arr[]={23,435,-32,238,0,45,-347,47,245,34,45998,237};

    quickSort(arr,0,11);

    for(int i=0;i<12;i++)
    cout<<arr[i]<<" ";
    
}