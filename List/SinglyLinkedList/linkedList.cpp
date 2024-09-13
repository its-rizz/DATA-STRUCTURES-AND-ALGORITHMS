#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
};



node *new_node(int data)
{
    
    node* t=new node();
    t->data=data;
    t->next=nullptr;
    return t;
}

node *kthnode(node *head,int k)
{
    node *temp=head;
    k--;
    while(temp and k--)
        temp=temp->next;
    return temp;
}

node* reverse(node *start)
{
    node *first,*second,*third;
    first=second=nullptr;
    third=start;
    while(third)
    {
        first=second;
        second=third;
        third=third->next;

        second->next=first;
    }
    return second;
}


class linkedList{
    node *head; //Points to head of the linkedList
    node *tail; //Points to the lastMost node of the linkedList
public:

    //It is the constructor and it will create the linkedList and initialise the head and tail as the nullptr
    linkedList(){
        head=nullptr;
        tail=nullptr;
    }

    void createList(int arr[],int n)
    {
        if(!head)
        {
            head=tail=new_node(arr[0]);
        }
        for(int i=1;i<n;i++)
        {
            tail->next=new_node(arr[i]);
            tail=tail->next;
        }
    }

    void insertAtBegining(int data)
    {
        //There are two pointer modification done
        node *temp=new_node(data);
        temp->next=head;
        head=temp;
    }


    void createLoop(int pos)
    {
        pos--;
        node *temp=head;
        while(pos--) temp=temp->next;
        tail->next=temp;
    }
    void insertAtEnd(int data)
    {
        node *temp=new_node(data);
        tail->next=temp;
        tail=temp;
    }

    void insertAtInd(int data,int ind)
    {
        //Here we are following the zero based indexing
        ind--;
        node *temp=head;
        while(ind--) temp=temp->next;
        node *t=new_node(data);
        t->next=temp->next;
        temp->next=t;
    }

    void deleteAtBegining()
    {
        node *t=head;
        head=head->next;
        free(t);
    }

    void deleteAtEnd()
    {
        node *temp=head;
        while(temp->next!=tail) temp=temp->next;
        temp->next=nullptr;
        free(tail);
        tail=temp;
    }

    void deleteAtIndex(int ind)
    {
        ind--;
        node *temp=head;
        while(ind--) temp=temp->next;
        node *t=temp->next;
        temp->next=t->next;
        free(t);
    }

    void printList()
    {
        node *temp=head;
        while(temp->next)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }

    void printRev(node *temp)
    {
        if(!temp)
            return;
        printRev(temp->next);
        cout<<temp->data<<" ";
    }

    void printRev()
    {
        printRev(head);
        cout<<endl;
    }

    void middleNode()
    {
        //If the number of node is even then it will print (n/2)+1 th node else n/2 th node
        node *slow,*fast;
        slow=fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<"Middle Node of the linkedlist is : "<<slow->data<<endl;
    }

    void reverseNode()
    {  
        //Three Pointers Approach
        node *first,*second,*third;
        first=second=nullptr;
        third=head;
        while(third)
        {
            first=second;
            second=third;
            third=third->next;
            second->next=first;
        }
        tail=head;
        head=second;
    }
    void recursiveReverseNode(node *prev,node *root)
    {
        if(!root)
        {
            head=prev;
            return;
        }
        recursiveReverseNode(root,root->next);
        root->next=prev;
    }
    void recursiveReverseNode()
    {
        tail=head;
        recursiveReverseNode(nullptr,head);
    }

    void nthNodeFromEnd(int k)
    {
        //Method 1-- This is two pass algorithm
        //-- nth node from the end == total#nodes-n+1 nodes from the start

        //Method 2-- Two Pointer Approach
        node *first,*second;
        first=second=head;

        int n=k;
        while(k--) second=second->next;

        //Taking the last node as first node from the end while(second)
        while(second->next)
        {
            first=first->next;
            second=second->next;
        }

        cout<<n<<"th Node from the end is :"<<first->data<<endl;

    }

    void totalNodes()
    {
        int count=0;
        node *temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        cout<<"Total number of nodes is :"<<count<<endl;
    }
    bool isLoopThere()
    {
        node *slow = head, *fast = head;
        while(fast!=nullptr and fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        if(fast==slow)
        {
            cout<<"There is a loop in the linked list"<<endl;
            return true;
        }

        else    
            cout<<"There is no loop in the linked list"<<endl;

        return false;
            
    }   

    void loopStarting()
    {
        node *slow = head, *fast = head;
        while(fast!=nullptr and fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        if(slow!=fast)
        {
            cout<<"There is no loop in the linkedList"<<endl;
            return;
        }

        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;

        }
        cout<<"The starting point of the loop is: "<<slow->data<<endl;
    }

    void loopLength()
    {
        node *slow = head, *fast = head;
        while(fast!=nullptr and fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }

        if(fast==slow)
        {
            int count=0;
            do{
                fast=fast->next;
                count++;
            }while(fast!=slow);

            cout<<"The total number of nodes in the linkedList is: "<<count<<endl;
        }
        else    
            cout<<"There is no loop in the linkedList"<<endl;
    }

    void reverseKpairs(int k)
    {
        //Creating the dummy node
        node *temp=new_node(-1);
        temp->next=head;
        node *prev=temp;

        while(prev->next)
        {
            node *start=prev->next;
            node *end=kthnode(start,k);
            if(end==nullptr)
                break;
            else
            {
                node *upcoming=end->next;
                end->next=nullptr;
                prev->next=reverse(start);
                start->next=upcoming;
                prev=start;
            }
        }

        head=temp->next;
    }

    void evenOdd()
    {
        //Traverse the two nodes at the time
            //1. If the temp is null then the even number of nodes in linkedList
            //2. Else odd number of nodes in the linkedList
        node *fast=head;
        while(fast and fast->next)
        {
            fast=fast->next;
            if(fast->next) fast=fast->next;
        }
        if(fast==nullptr) cout<<"The linkedList has even number of nodes"<<endl;
        else    
            cout<<"The linkedList has odd number of nodes"<<endl;
    }

    void isPalindrome()
    {
        node *slow,*fast;
        slow=fast=head;

        node *tail=nullptr;
        while(fast and fast->next)
        {
            tail=slow;
            slow=slow->next;
            fast=fast->next;
            if(fast->next) fast=fast->next;
        }

        tail->next=nullptr;
        node *l2=reverse(slow);

        node *first,*second;
        first=head;
        second=l2;

        bool palindrome=true;

        while(first and second)
        {   
            if(first->data!=second->data)
            {
                palindrome=false;
                break;
            }
            first=first->next;
            second=second->next;
        }

        if(palindrome)
            cout<<"The given linkedList is palinrome"<<endl;
        else
            cout<<"The given linkedList is not palindrome"<<endl;
        
        tail->next=reverse(l2);
        
    }
};

int main()
{
    int arr[]={1,2,3,2,5};
    int n=sizeof(arr)/sizeof(int);
    linkedList l; //Note here that unlike java we don't have to use the new keyword for creating the new linkedList
    l.createList(arr,n);
    l.printList();


    l.isPalindrome();
}