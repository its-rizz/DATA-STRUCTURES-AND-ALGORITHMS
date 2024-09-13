#include <bits/stdc++.h>
#include<iostream>
using namespace std;


//The structure of the node
class node {
public:
    int data; 
    node *next;
};

//Function that takes data as input and return the new_node
node* new_node(int data) 
{
    node *newNode=new node;
    newNode->data=data;
    newNode->next=nullptr;
    return newNode;
}

//Find the middle element of the linkedList
node* middle(node *head) 
{
    if (!head or !head->next) 
    	return head;
    
    node *slow=head;
    node *fast=head->next;
    
    while(!fast and !fast->next)
    {
   	fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

//Merge two linkedList
node* merge(node *l1, node *l2) 
{
    node *dummy=new_node(-1);
    node *temp=dummy;
    
    while (l1 and l2) 
    {
        if (l1->data<l2->data)
        {
            temp->next=l1;
            l1=l1->next;
        }
        else 
        {
            temp->next=l2;
            l2= l2->next;
        }
        temp=temp->next;
    }

    if (l1) temp->next=l1;
    if (l2) temp->next=l2;
    
    return dummy->next;
}

//Class for the linkedList
class linkedList 
{
    node *head;
public:
    linkedList():head(nullptr) {}
    
    void createLinkedList(int arr[], int n) 
    {

        head=new_node(arr[0]);
        node *temp=head;
        for (int i=1;i<n;i++) 
        {
            temp->next=new_node(arr[i]);
            temp=temp->next;
        }
    }
    
    void printList() 
    {
        node *temp=head;
        while(temp) 
        {
            cout << temp->data<<" ";
            temp=temp->next;
        }
        cout << endl;
    }
    
    node* mergeSort(node *head) {
        if (!head or !head->next) return head;
        
        node *middleNode=middle(head);
        node *nextNode=middleNode->next;
        middleNode->next=nullptr;
        
        node *left=mergeSort(head);
        node *right=mergeSort(nextNode);
        
        return merge(left,right);
    }
    
    void mergeSort() 
    {
        head=mergeSort(head);
    }
};

int main() {
    linkedList l;
    int arr[] = {2, 3, 1, 4, 64, 5};
    int n = sizeof(arr) / sizeof(int);
    l.createLinkedList(arr, n);
    l.mergeSort();
    l.printList();
}
