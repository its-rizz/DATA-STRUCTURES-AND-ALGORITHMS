#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Selection sort
void selectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int ind=i;
        int element=arr[ind];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<element)
            {
                element=arr[j];
                ind=j;
            }
        }
        swap(arr[i],arr[ind]);
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[]={342,32,2,123,52};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    printArray(arr,n);
}