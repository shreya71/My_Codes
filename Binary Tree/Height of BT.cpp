/******************************************************************************
HEIGHT OF A BINARY TREE

Height of a binaru tree is the tree's deepest node.

BINARY TREE
                       1                        
                     /  \
                    2    3                  Height = 3
                   / \  / \
                  4  5 6   7 <- deepest node(any node of this lvl)
                  
Time Complexity = O(N)

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

int height(Node* root)
{
    if(root == NULL)
    return 0;
    int left_height = height(root->left), right_height = height(root->right) ;
    return max(left_height, right_height) + 1 ;
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
  
  cout << height(root) << endl;
  return 0;
}
