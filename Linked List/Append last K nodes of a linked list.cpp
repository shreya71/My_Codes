// Originally                              7->5->1->2->NULL
//After apprnding from k = 2               1->2->7->5->NULL

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
int length(node* head)
{
    int l = 0;
    node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
node* appendk(node* &head, int k)
{
    node *newhead, *newtail, *tail = head;
    int l = length(head) , count = 1;
    k = k%l;                                  // if in case k>l
    while(tail->next != NULL)
    {
        if(count == l-k )
        newtail = tail;
         if(count == l-k+1 )
        newhead = tail;
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;               // head here is the original head
    return newhead;
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
int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtHead(head, 5);
    insertAtHead(head, 7);
    display(head);
    node* newhead = appendk(head, 2);
    display(newhead);
}
