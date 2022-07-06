/***********************************************************************************************************************************************************
PROBLEM: Print all nodes at distance K. 
    Given: *root, *node, K

APPROACH: Case 1: Node's subtree
                  We start from k (given). as we jump to nodes child, we decrment k by 1,
                  as soon as k = 0, the child->data is stored which is our ans.
          Case 2: Node's ancestors
                  We consider the ancestor of target node, then we find distance of target node from ancestor say d,
                  for all ancestors we search other subtree nodes at (k-d). if target node is in left we search right,
                  and vice versa.
                  Reduced Problem: case 2 reduces to case 1at point for finding nodes at (k-d).

BINARY TREE
                       1                                   1          
                     /  \                                 /              
                    2    3                               2             
                   / \  / \                             / \              
                  4  5 6   7                           4  5
                  
*****************************************************************************************************************************************************************/

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

//case 1
void printSubtree_nodes(Node* root, int k)
{
    if(root == NULL || k < 0)              // no possibilities
    return;
    if(k == 0)                            // reached ans
    {
    cout << root->data << " " ;
    return;
    }
    printSubtree_nodes(root->left, k-1);
    printSubtree_nodes(root->right, k-1);
}

//case 2                  here we return d (dist b/w target and ancestor) and return to reduce it further to case 1
int printNodesAt_K(Node* root, Node* target, int k)
{
    if(root == NULL)                       // target node not found
    return -1;
    if(root == target)                    // d = 0
    {
        printSubtree_nodes(root, k) ;
        return 0;
    }
    int dl = printNodesAt_K(root->left, target,  k);
    if(dl != -1)
    {
        if(dl + 1 == k)
        cout << root->data <<" " ;
        else
        printSubtree_nodes(root->right, k-dl-2);        //we r calling root-> right sp 1 and from root->left + 1 = 2
        return 1+dl;                                    //
    }
    
    int dr = printNodesAt_K(root->right,target,  k);
    if(dr != -1)
    {
        if(dr + 1 == k)
        cout << root->data <<" " ;
        else
        printSubtree_nodes(root->left, k-dr-2);        //we r calling root-> right sp 1 and from root->left + 1 = 2
        return 1+dr;                                    //
    }
    return -1;                                // root != target, root->right != target, root->left != target
}

int main ()
{
  struct Node *root = new Node (1);
  root->left = new Node (2);
  root->right = new Node (3);
  root->left->left = new Node (4);
  root->left->right = new Node (5);
  //root->right->left = new Node (6);
  //root->right->right = new Node (7);
  
  printNodesAt_K(root, root->left, 1) ;
}
