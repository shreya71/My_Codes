/***********************************************************************************************************************************************
PROBLEM: Given a Binary tree, flatten it into a linked list in-place. After flattening, left of each node should
         point NULL and right should contain next node in preorder sequence. (it's NOT allowed to use another
         data structure)

APPROACH: 1. Recursively flatten left & right subtrees.
          2. Store the left tail and the right tail.
          3. Store the right subtree in temp and make left subtree as the right subtree
          4. Join right subtree with left tail.
          5. Return the right tail.

BINARY TREE
                       1                                   1          
                     /  \                                 /              
                    2    3                               2             
                   / \  / \                             / \              
                  4  5 6   7                           4  5
                  
***************************************************************************************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *right;
  struct Node *left;

    Node (int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void flatten(Node* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))    // tree already flattened so we return tail
    return;
    if(root->left != NULL)  {                  
    flatten(root->left) ;
    Node* temp = root->right;
    root->right = root->left;                                         // flatten root->left becomes root->right
    root->left = NULL;
    
    Node* t = root->right;                                            // to calculate tail to get append temp to tail
    while(t->right != NULL)
    {
        t = t->right ;
    }
    t->right = temp ;
    }
    flatten(root->right) ;
}

void inorder(Node* root)
{
    if(root == NULL)
    return ;
    inorder(root->left);
    cout << root->data << " " ;
    inorder(root->right);
}

int main ()
{
  struct Node *root = new Node (1);
  root->left = new Node (2);
  root->right = new Node (3);
  root->left->left = new Node (4);
  root->left->right = new Node (5);
  root->right->left = new Node (6);
  root->right->right = new Node (7);
  
  flatten(root) ;
  inorder(root);
  cout << endl;
}
