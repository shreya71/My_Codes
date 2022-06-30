/******************************************************************************
PROBLEM: Sum of all nodes present in a binary tree.

APPROACH: Left subtree sum + right subtree sum + node value.
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

int sumnode(Node* root)
{
    if(root == NULL)
    return 0;
    return sumnode(root->left) + sumnode(root->right) + root->data ;
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
  //count of nodes
  cout << sumnode(root) << endl;
  return 0;
}
