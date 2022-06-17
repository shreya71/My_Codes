#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node              
{
    public:
    int data;
    node* next;
    node(int val)         
    {
        data = val;
        next = NULL;
    }
};
void insertAtTail(node* &head, int val)      
{
    node* n = new node(val);     
     if(head == NULL)           
    {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    temp = temp->next;
    temp->next = n;               
}
void even_after_odd(node* &head)
{
    node *odd = head, *even = head->next;
    node *evenstart = even;
    while(odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if(odd->next != NULL)
    even->next = NULL;
}
void display(node* head)            
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
    int A[] = {1, 2, 3, 4, 5, 6};
    for(int i =0; i< 6; i++)
    insertAtTail(head, A[i]);
    display(head);
    even_after_odd(head);
    display(head);
}
