/*********************************************************************************************************      
      1. Using iteration method, three pointers used. Prev. pointed to NULL, current to head and next pointer next to current, transverse till
         current iteratot not equal to NULL
      2. Using Recursion, take head as node and reverse rest of LL by introducing a newhead, at last set last node to head and prev. to head NULL
*************************************************************************************************************/

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
node* reverse1(node* &head)                         //Iterator method using 3 pointers
{
    node *prev = NULL, *current = head, *nextptr ;
    while(current != NULL)               // till current reaches NULL
    {
        nextptr = current->next;
        current->next = prev;
        prev = current;
        current = nextptr;
    }
    return prev;              // new  head
}
node* reverse2(node* &head)                           //Recursive Method 
{
    if(head == NULL || head->next == NULL)
    return head;                                     
    node* temp = reverse2(head->next);         
    head->next->next = head;
    head->next = NULL;
    return temp;
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
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 9);
    display(head);
    node* newhead1 = reverse1(head);                   //Iterator method using 3 pointers
    display(newhead1);
    node* newhead2 = reverse2(newhead1);              //Recursive Method 
    display(newhead2);
}
