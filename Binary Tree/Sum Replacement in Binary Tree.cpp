/******************************************************************************
PROBLEM: Calculate the sum of subtrees and current node and replace it with the current node.

APPROACH: Left subtree sum value + right subtree sum value + current node value.
BINARY TREE
                       1
                     /  \
                    2    3
                   / \  / \
                  4  5 6   7
*******************************************************************************/
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

void sumReplace(Node* root)
{
    if(root == NULL)
    return;
    sumReplace(root->right);
    sumReplace(root->left);
    if(root->right != NULL)
    root->data += root->right->data;
    if(root->left != NULL)
    root->data += root->left->data;
}

void preorder(Node* root)
{
    if(root == NULL)
    return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
  
  preorder(root);
  sumReplace(root) ;
  cout << endl;
  preorder(root);
  cout << endl;
  return 0;
}
