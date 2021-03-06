/******************************************************************************
BINARY TREE
                       1
                     /  \
                    2    3
                   / \  / \
                  4  5 6  7
                       
LEVEL ORDER TRAVERSAL: Traversing each level of tree one by one in order starting from root(0 level)
                       value: 1, 2, 3, 4, 5, 6, 7
*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data ;
    struct Node* right ;
    struct Node* left ;
    
    Node(int val)
    {
        data = val;
        left = NULL ;
        right = NULL;
    }
};

void Printlevel(Node* root)
{
    if(root == NULL)
    return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
    Node* node = q.front();
    q.pop();
    if(node != NULL){
    cout << node->data << " " ;
    if(node->left)
    q.push(node->left);
    if(node->right)
    q.push(node->right);
    }
    else if(!q.empty())
    q.push(NULL);
    }
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Printlevel(root);
    return 0;
}
