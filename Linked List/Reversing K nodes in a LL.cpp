#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node                  // node is not in-nuilt we have to make it
{
    public:
    int data;
    node* next;
    node(int val)           //constructor
    {
        data = val;
        next = NULL;
    }
};
// Inserting element at tail of a linked list 
void insertAtTail(node* &head, int val)       // taking head by reference as we modify our LL
{
    node* n = new node(val);     // node n having data->val and next->NULL
     if(head == NULL)           //condition when no node is present in LL
    {
        head = n;
        return;
    }
    // iterator to traverse till last node
    node* temp = head;
    while(temp->next != NULL)
    temp = temp->next;
    temp->next = n;               //node n inserted and NULL is automatically assigned to its next
}
// Inserting element at head of a linked list
void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
        head = n;
}
// To print the elements of the linked list
void display(node* head)            // head passed by value since no modifications are to be made
{
    node* temp = head;
    while(temp != NULL)
    {
    cout << temp->data << "->" ;
    temp = temp->next ;
    }
    cout << "NULL" <<  endl;
}
node* reversek(node* &head, int k)
{
    node *curr = head, *prev = NULL, *nextptr ;
    int count = 0;
    while(curr != NULL && count < k)         // using iteration method to reverse upto first set of k nodes
    { 
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;                        
    }
    // from next element we make a recursive function to perform above step for every k nodes till NULL
    if(nextptr != NULL)
    head->next = reversek(nextptr, k) ;
    return prev ;
    // on reversing we get prev pointer on last node & head remains at same place
    // to connect to further LL we perform recursion from head->next element
}
int main()
{
    node* head = NULL;
    int k;
    cin>> k;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    display(head) ;
    insertAtHead(head, 5);
    insertAtHead(head, 7);
    display(head);
    node* newhead = reversek(head, k);
    display(newhead);
}
