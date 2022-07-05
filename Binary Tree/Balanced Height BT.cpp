/******************************************************************************
PROBLEM: To find wheter the height of Binary Tree is balanced or not.
BALANCED HEIGHT TREE: For each node, the difference betweeen the heights of the left subtree n right subtree <= 1.

APPROACH: Findint at each node the abs diff of left n right heights n if at any point
          difference is > 1 then return unbalanced.

BINARY TREE
                       1                                   1
                     /  \                                 / 
                    2    3        Balanced   ;           2             Unbalanced ;
                   / \  / \                             / \
                  4  5 6   7                           4  5
                  
*******************************************************************************/

//Time Complexity: O(N^2)

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
    int lh= height(root->left) ;
    int rh= height(root->right) ;
    return max(lh, rh)+1 ;
}

bool balanced(Node* root)
{
    if(root == NULL)
    return 1;
    if(balanced(root->left) == false)
    return 0;
    if(balanced(root->right) == false)
    return 0;
    int lh= height(root->left) ;                     // to check balance on current node
    int rh= height(root->right) ;
    if(abs(lh-rh) <= 1)
    return 1;
    else
    return 0;
}

int main ()
{
  struct Node *root = new Node (1);
  root->left = new Node (2);
  //root->right = new Node (3);
  root->left->left = new Node (4);
  root->left->right = new Node (5);
  //root->right->left = new Node (6);
  //root->right->right = new Node (7);
  
  if(balanced(root) == 1)
  cout << "Balanced Tree" << endl;
  else
  cout << "Unbalanced Tree" << endl;
  return 0;
}

// ######################################################################################################

// Time Complexity: O(N) 

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

bool balanced(Node* root, int *height)
{
    int lh = 0, rh = 0;
    if(root == NULL)
    return 1;
    if(balanced(root->left, &lh) == false)
    return 0;
    if(balanced(root->right, &rh) == false)
    return 0;
    *height = max(lh, rh) + 1 ;
    if(abs(lh-rh) <= 1)
    return 1;
    else
    return 0;
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
  int height= 0;
  if(balanced(root, &height) == 1)
  cout << "Balanced Tree" << endl;
  else
  cout << "Unbalanced Tree" << endl;
  return 0;
}
