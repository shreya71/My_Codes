/******************************************************************************
Building tree from preorder and inorder

BINARY TREE 
                       1
                     /  \
                    2   3
                  / \  / \
                 4  5 6  7 

1. Preorder Traversal: Write the value of present root then go onto root's left subtree(left node)
                       then go to rifht subtree.
                       Preorder traversal value: 1, 2, 4, 5, 3, 6, 7
                       
2. Inoder Traversal: Travel the left subtree of a root first (travelling n writing values), then
                     travel the root n then the right subtree of the root.
                     Inorder traversal value: 4, 2, 5, 1, 6, 3, 7

For the tree formation using above two traversals we traverse the elements of tree in preorder and find it's 
index in inorder and work accordingly.
                        
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

int search(int inorder[], int start, int end, int cur)
{
    for(int i = start ; i<= end ; i++)
    {
        if(inorder[i] == cur)
        return i;
    }
    return -1;                 // this is never returned since cur is always present inorder
}

Node* buildTree(int preorder[], int inorder[], int start, int end) //start n end wrt inorder
{
    static int idx = 0;      // for preorder which represent pos of index and increments by 1 everytime
    
    if(start > end)          // base case
    return NULL ;     
    
    int cur = preorder[idx];
    idx++;
    Node* node = new Node(cur);                     // right n left subtree for this node to be build
    
    if(start == end)
    return node;
    
    int pos = search(inorder, start, end, cur) ;    // to find pos of cur in inorder n store in pos
    node->left = buildTree(preorder, inorder, start, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, end);
    return node;
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
    int preorder[] = {1, 2, 4, 3, 5} ;
    int inorder[] = {4, 2, 1, 5, 3} ;
    
    //building tree
    Node* root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);          // if this same as inorder arr that means we have build the tree crctly
    cout << endl ;

    return 0;
}
