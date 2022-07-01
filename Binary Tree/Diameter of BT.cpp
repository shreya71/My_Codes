/******************************************************************************
DIAMETER OF A BINARY TREE

Diameter of a binary tree is the number of nodes in the longest path between any 2 leaves.
TWO CASES: 1. If diameter includes current node, then diameter = left tree height + right tree height + 1
           2. Current node excluded, diameter = max(left diameter, right diameter)
   So, as a result is diameter = MAX(left tree height + right tree height + 1, left diameter, right diameter)

BINARY TREE
                       1                        
                     /  \
                    2    3                  Diameter = 5
                   / \  / \
                  4  5 6   7 <- deepest node(any node of this lvl)
                  
Time Complexity = O(N^2)

OPTIMIZED SOLUTION: instead of calculating height in other function we take height as a pointer n pass in the 
                    same recursive function.
                    Time Complexity: O(N)
*******************************************************************************/

// TC : O(N^2)

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

int diameter(Node* root)
{
    if(root == NULL)
    return 0;
    int left_height = height(root->left), right_height = height(root->right) ;
    int curdiameter = left_height + right_height + 1 ;
    return max(curdiameter, max(left_height, right_height)) ;
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
  
  cout << diameter(root) << endl;
  return 0;
}

//***********************************************************************************************************

// TC : O(N)

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

int diameter(Node* root, int* height)
{
    if(root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int rd = diameter(root->left, &lh);
    int ld = diameter(root->right, &rh);
    int curdiam = lh + rh + 1 ;
    *height = max(lh, rh) + 1;
    return max(curdiam, max(ld, rd)) ;
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
  int height = 0;
  cout << diameter(root, &height) << endl;
  return 0;
}
