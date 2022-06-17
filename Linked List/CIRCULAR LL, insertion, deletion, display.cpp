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
void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != head)
    temp = temp->next;
    temp->next = n;               
    n->next = head;
        head = n;
}
void insertAtTail(node* &head, int val)       
{
    node* n = new node(val);     
     if(head == NULL)           
    {
        insertAtHead(head, val);
        return;
    }
    node* temp = head;
    while(temp->next != head)
    temp = temp->next;
    temp->next = n;               
    n->next = head; 
}
void deleteAtHead(node* &head)
{
    node* temp = head;
    while(temp->next != head)
    temp = temp->next;
    node* to_delete = head;
    temp->next = head->next;
    head = head->next;
    delete to_delete;
}
void deletion(node* &head, int pos)
{
    if(pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 0;
    while(count != pos-1)
    {
        temp = temp->next;
        count++;
    }
    node* to_delete = temp->next;
    temp->next = temp->next->next ;
    delete to_delete;
}
void display(node* head)           
{
    node* temp = head;
    do
    {
    cout << temp->data << " " ;
    temp = temp->next ;
    }
    while(temp != head);
    cout <<  endl;
}
int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    display(head);
    insertAtHead(head, 7);
    insertAtHead(head, 9);
    display(head);
    deletion(head, 1);
    display(head);
    deletion(head, 4);
    display(head);
}
