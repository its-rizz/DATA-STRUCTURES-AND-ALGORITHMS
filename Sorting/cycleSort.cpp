#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void cycleSort(int arr[],int n)
{
    for(int cs=0;cs<n-1;cs++)
    {
        int currentItem=arr[cs];
        int pos=cs;

        //Find the number of elements in the array that is smaller than the current element
        for(int i=cs+1;i<n;i++)
            pos=arr[i]<currentItem?pos+1:pos;
        swap(currentItem,arr[pos]);

        //Repeating the process untill the correct element comes into my position
        while(pos!=cs)
        {
            pos=cs;
            for(int i=cs+1;i<n;i++)
                pos=arr[i]<currentItem?pos+1:pos;
            swap(currentItem,arr[pos]);
        }
    }
}


void printArray(int arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[]={20,40,50,10,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    cycleSort(arr,n);
    printArray(arr,n);
}