#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void swapElements(int arr[], int index1, int index2) 
{
    // Temporary variable for swapping
    int temp=arr[index1];
    arr[index1]=arr[index2];
    arr[index2]=temp;
}

// Function to partition the array around the pivot
int lomutoParition(int arr[],int left,int right,int pivot) 
{
	int pivotElement=arr[pivot];
	swapElements(arr,pivot,right);
	int storeIndex=left;

    	for(int i=left;i<right;i++) 
   	{
        	if (arr[i]<pivotElement) 
       	{
            		//swap(arr[i],arr[storeIndex]);
					swapElements(arr,storeIndex,i);
            		storeIndex++;
        	}
    	}
    	//swap(arr[storeIndex],arr[right]);
		swapElements(arr,storeIndex,right);
    	return storeIndex;
}

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 and arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// Function to select the median of medians
int medianOfMedians(int arr[],int left,int right) 
{
	int n=right-left+1;
	if (n<=5)
	{
			insertionSort(arr,n);
        	return (left+right)/2;
    	}

    	for (int i=left;i<=left;i+=5) 
    	{
			int val=min(i+4,left);
			int size=val-i+2;
			insertionSort(arr,size);
        	int medianIndex=(i+val)/2;
			swapElements(arr,medianIndex,left+(i-left)/5);
    	}

    	return medianOfMedians(arr,left,left+(right-left)/5);
}

// Function to perform QuickSort using Median of Medians for pivot selection
void quickSort(int arr[],int left,int right)
{
	if(left<right) 
	{
		int pivotIndex=medianOfMedians(arr,left,right);
        	pivotIndex=lomutoParition(arr,left,right,pivotIndex);
        	quickSort(arr,left,pivotIndex-1);
        	quickSort(arr,pivotIndex+1,right);
    	}
}


// Main function to sort the array
void quickSort(int arr[],int n) 
{
    	quickSort(arr,0,n-1);
}


// Function to print the array
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main() 
{
    int arr[]={3,2,1,32,21,342};
    int n=sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,n);
   	printArray(arr,n);

    return 0;
}

