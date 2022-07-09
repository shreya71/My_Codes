/**********************************************************************************************************************************************
PROBLEM: Find the distance between two nodes in a binary tree. The distance between the two nodes is the
         minimum number of edges to be traversed to reach one node from another.

APPROACH: let the two nodes be n1 and n2, We first find the LCA for two nodes(Lowest Common Ancestor).
          Find the distance of n1 and n2 from LCA say. d1 and d2 respectively, return d1+d2.

BINARY TREE
                       1                                   1          
                     /  \                                 /              
                    2    3                               2             
                   / \  / \                             / \              
                  4  5 6   7                           4  5
                  
************************************************************************************************************************************************/
// Time Complexity : O(N) but we r traversing same tree multile times

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

bool getPath(Node* root, int key, vector<int> &path)
{
    if(root == NULL)
    return false;
    path.push_back(root->data);                  //assuming we are on a right path
    if(root->data == key)
    return true;
    if(getPath(root->left, key, path) || getPath(root->right, key, path))
    return true;
    path.pop_back();
    return false;
}

int lca(Node* root, int n1, int n2)
{
    vector<int> p1, p2 ;
    if(!getPath(root, n1, p1) || !getPath(root, n2, p2))     // To check whether we get a path for n1 and n2, returns bool value
    {
        return -1;
    }
    int pc;                  //path change
    for(pc = 0; pc < p1.size() && p2.size(); pc++)
    {
        if(p1[pc] != p2[pc])
        break;
    }
    return p1[pc-1] ;
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
  int n1 = 7, n2 = 6;
  cout << lca(root, n1, n2)  << endl;
  return 0;
  
}

// ######################################################################################################################################################################33

// Time Complexity : O(N)                 Here we traverse the tree only once

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

Node* lca2(Node* root, int n1, int n2)      // return type node pointer, to access  entire node
{
    if(root == NULL)
    return NULL;
    if(root->data == n1 || root->data == n2)
    return root;
    Node* leftlca = lca2(root->left, n1, n2);
    Node* rightlca = lca2(root->right, n1, n2);
    if(leftlca && rightlca)
    return root;
    if(leftlca != NULL)
    return leftlca ;
    return rightlca;
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
  int n1 = 7, n2 = 6;
  Node* l = lca2(root, n1, n2) ;
  cout << l->data  << endl;
  return 0;
  
}
