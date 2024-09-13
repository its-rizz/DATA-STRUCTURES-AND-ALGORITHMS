#include<bits/stdc++.h>
#include<iostream>
using namespace std;


//Function to heapify the array
void heapify(int arr[],int n,int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n and arr[left]>arr[largest]) largest=left;
	if(right<n and arr[right]>arr[largest]) largest=right;
	if(largest!=i)
	{
		//swapping the elements
		int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
		heapify(arr,n,largest);
	}	
	
}

//Main logic of the heapSort
void heapSort(int arr[],int n)
{	
	//Creating the maxHeap
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
		
	for(int i=n-1;i>=0;i--)
	{
		//swapping the elements
		int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
		heapify(arr,i,0);
	}
}



//Print the array
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}




int main() 
{
    int arr[]={3,23,4,32,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
	heapSort(arr,n);
   	printArray(arr,n);

    return 0;
}

