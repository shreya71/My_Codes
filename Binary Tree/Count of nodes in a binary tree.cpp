/******************************************************************************
PROBLEM: Count total nodes present in a binary tree.

APPROACH: Left subtree count + right subtree count + 1(root node).
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

int countnode(Node* root)
{
    if(root == NULL)
    return 0;
    return countnode(root->left) + countnode(root->right) + 1 ;
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
  cout << countnode(root) << endl;
  return 0;
}
