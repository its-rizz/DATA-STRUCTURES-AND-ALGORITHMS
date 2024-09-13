#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void countSort(int arr[],int n,int exp)
{
    int count[10]={0};
    int output[n];

    for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i]=count[i]+count[i-1];

    for(int i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
        arr[i]=output[i];

}

void radixSort(int arr[],int n)
{
    //Find the max element for the number of passes
    int mx=arr[0];
    for(int i=1;i<n;i++)
        mx=arr[i]>mx?arr[i]:mx;
    
    //Number of passes
    for(int exp=1;mx/exp>0;exp*=10)
        countSort(arr,n,exp);
}


void printArray(int arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[]={20,40,50,10,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    printArray(arr,n);
}