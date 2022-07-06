/*****************************************************************************************************************************************
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
                  
********************************************************************************************************************************************/

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

Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL)
    return NULL;                                                                    // LCA can't be found
    if(root->data == n1 || root->data == n2)
    return root;                                                                   // for this case in this level LCA is root
    // if not found we go fot tLCA in right and left subtree
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    
    if(left != NULL && right != NULL)                                             // => we got n1 or n2 in left or n1 or n2 in right so root becomes LCA
    return root;
    if(left == NULL && right == NULL)                                             // => LCA not  found
    return NULL;
    if(left != NULL )                                                           // => LCA not found in right subtree but can be in left subtree
    return LCA(root->left, n1, n2);
    // => LCA not found in left subtree but can be in right subtree
    return LCA(root->right, n1, n2);
}

// we measure distance in form of levels
int distance(Node *root, int k, int dist)                                          // k-> kaha tak ka distance find kr rhe
{
    if(root == NULL)
    return -1;
    if(root->data == k)
    return dist ;
    int left = distance(root->left, k, dist+1);
    if(left != -1)
    return left;
    return distance(root->right, k, dist+1);
}

int finaldistance(Node *root, int n1, int n2)
{
    Node* lca = LCA(root, n1, n2);
    int d1 = distance(lca, n1, 0);           // 0 is the initial distance
    int d2 = distance(lca, n2, 0);          // 0 is the initial distance
    return d1+d2 ;
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
  
  cout << finaldistance(root, 4, 7) << endl;
}
