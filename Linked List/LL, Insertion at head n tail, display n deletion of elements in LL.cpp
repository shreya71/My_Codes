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
//Deletion of an element of LL
void deletion(node* &head, int val)
{
    node* n = new node(val);
    node* temp = head;
    while(temp->next->data != val)
    temp = temp->next;
    node* to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
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
    display(head) ;
    insertAtHead(head, 5);
    insertAtHead(head, 7);
    display(head);
    deletion(head, 5);
    display(head);
}
