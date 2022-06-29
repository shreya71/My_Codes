/******************************************************************************
Building tree from postorder and inorder

BINARY TREE 
                       1
                     /  \
                    2   3
                  / \  / \
                 4  5 6  7 

1. Postorder Traversal: Travel the left subtree of a root first (travelling n writing values), then
                        travel the right subtree of the root n then the root.  
                        Postorder traversal value: 4, 5, 2, 6, 7, 3, 1
                       
2. Inoder Traversal: Travel the left subtree of a root first (travelling n writing values), then
                     travel the root n then the right subtree of the root.
                     Inorder traversal value: 4, 2, 5, 1, 6, 3, 7

For the tree formation using above two traversals we traverse the elements of tree in preorder and find it's 
index in inorder and work accordingly.
Postorder is opposite of preorder, so we start with last element and in preorder we started with 1st element.

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

int search(int inorder[], int start, int end, int val)
{
    for(int i = start ; i<= end ; i++)
    {
        if(inorder[i] == val)
        return i;
    }
    return -1;                 // this is never returned since cur is always present inorder
}

Node* buildTree(int postorder[], int inorder[], int start, int end)   //start n end wrt inorder
{
    static int idx = 4;   //(n-1) n->array size   // for preorder which represent pos of index and increments by 1 everytime
    
    if(start > end)          // base case
    return NULL ;     
    
    int val = postorder[idx];
    idx--;
    Node* cur = new Node(val);                     // right n left subtree for this node to be build
    
    if(start == end)
    return cur;
    
    int pos = search(inorder, start, end, val) ;    // to find pos of cur in inorder n store in pos
    cur->right = buildTree(postorder, inorder, pos+1, end);
    cur->left = buildTree(postorder, inorder, start, pos-1);
    return cur;
}

// to verify whether the built rootnode is crct or not
void inorderPrint(Node* root)
{
    if(root == NULL)
    return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int postorder[] = {4, 2, 5, 3, 1} ;
    int inorder[] = {4, 2, 1, 5, 3} ;
    
    //building tree
    Node* root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);          // if this same as inorder arr that means we have build the tree success
    cout << endl ;

    return 0;
}
