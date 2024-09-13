#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bucketSort(int arr[],int n,int k)
{
    //Find the maximum element in the array
    int maxVal=arr[0];
    for(int i=1;i<n;i++)
        maxVal=arr[i]>maxVal?arr[i]:maxVal;
    maxVal++;

    //Creating the k buckets
    vector<int> bkt[k];

    //Filling the data into the buckets
    for(int i=0;i<n;i++)    
    {
        int bi=(k*arr[i])/maxVal;
        bkt[bi].push_back(arr[i]);
    }

    //Sort the buckets
    for(int i=0;i<k;i++)
        sort(bkt[i].begin(),bkt[i].end());
    
    int index=0;
    //Joining the buckets
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<bkt[i].size();j++)
            arr[index++]=bkt[i][j];
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
    int arr[]={20,80,10,85,75,99,18};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=5;
    bucketSort(arr,n,k);
    printArray(arr,n);

}