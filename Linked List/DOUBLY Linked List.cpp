// DOUBLY Linked List 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node                  // node is not in-built we have to make it
{
    public:
    int data;
    node *next, *prev;
    node(int val)           //constructor
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
// Inserting element at head of a  Doubly linked list
void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    if(head != NULL)
        head->prev = n;        // this is a problem for head = NULL
        head = n;             // head becomes the first node
}
// Inserting element at tail of a  Doubly linked list 
void insertAtTail(node* &head, int val)       // taking head by reference as we modify our  Doubly LL
{
    node* n = new node(val);     // node n having data->val and next->NULL
     if(head == NULL)           //condition when no node is present in  Doubly LL
    {
        insertAtHead(head, val);
        return;
    }
    // iterator to traverse till last node
    node* temp = head;
    while(temp->next != NULL)
    temp = temp->next;
    temp->next = n;               //node n inserted and NULL is automatically assigned to its next
    n->prev = temp;
}
void deleteAtHead(node* &head)          // function to delete element at node of a doubly linked list
{
    node* to_delete =head;
    head = head->next;
    head->prev = NULL;
    delete to_delete;
}
//Deletion of an element of doubly LL
void deletion(node* &head, int pos)
{
    if(pos == 1)
    {
    deleteAtHead(head);
    return;
    }
    int count = 1;                       // to reach pos
    node* temp = head;
    while(temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    node* to_delete = temp;
    temp->prev->next = temp->next;
    if(temp->next != NULL)
    temp->next->prev = temp->prev;                 // creates problem if temp->next is NULL
    delete to_delete;
}
// To print the elements of the Doubly linked list
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
    display(head) ;
    insertAtHead(head, 5);
    insertAtHead(head, 7);
    display(head);
    deletion(head, 3);
    display(head);
    deletion(head, 1);
    display(head);
    deletion(head, 2);
    display(head);
}
