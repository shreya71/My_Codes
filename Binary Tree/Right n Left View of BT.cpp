/******************************************************************************
RIGHT VIEW AND LEFT VIEW OF A BINARY TREE

APPROACH: Rightmost node at a level required. So we traverse level wise(level order traversal)
          Leftmost node at a level required. So we traverse level wise(level order traversal)

BINARY TREE
                       1          Left view:               1           Left view:
                     /  \           1, 2, 4               /              1, 2, 4
                    2    3        Right view:            2             Right View:
                   / \  / \         1, 3, 7             / \              1, 2, 5
                  4  5 6   7                           4  5
                  
*******************************************************************************/

// 1. Right View

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

void rightview(Node *root)
{
    if(root == NULL)
    return;
    queue<Node*> q ;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size() ;
        for(int i = 0; i< n; i++)
        {
            Node* cur = q.front() ; 
            q.pop();
            if(i == n-1)
            cout << cur->data << " " ;
            if(cur->left != NULL)
            q.push(cur->left) ;
            if(cur->right != NULL)
            q.push(cur->right) ;
        }
    }
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
  
  rightview(root) ;
}

//###############################################################################################

// 2. Left View

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

void leftview(Node *root)
{
    if(root == NULL)
    return;
    queue<Node*> q ;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size() ;
        for(int i = 0; i< n; i++)
        {
            Node* cur = q.front() ; 
            q.pop();
            if(i == 0)
            cout << cur->data << " " ;
            if(cur->left != NULL)
            q.push(cur->left) ;
            if(cur->right != NULL)
            q.push(cur->right) ;
        }
    }
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
  
  leftview(root) ;
}
