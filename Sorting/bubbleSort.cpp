#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n)
{
    for(int pass=0;pass<n-1;pass++)
    {
        bool swapped=false;
        for(int i=0;i<n-1-pass;i++)
        {
            if(arr[i]>arr[i+1])
            {   
                swapped=true;
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        if(!swapped) break;
    }
    return;
}



int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i>n;i++) cin>>arr[i];
    bubbleSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}