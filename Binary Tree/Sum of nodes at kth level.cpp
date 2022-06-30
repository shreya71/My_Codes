/******************************************************************************
PROBLEM: Find the sum of nodes at Kth level.

BINARY TREE
                       1
                     /  \
                    2    3
                   / \  / \
                  4  5 6  7
                       
LEVEL ORDER TRAVERSAL
value: 1, 2, 3, 4, 5, 6, 7         sum at 2nd lvl = 4+5+6+7 = 22
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

int
sumAtK (Node * root, int K)
{
  if (root == NULL)
    return -1;
  queue < Node * >q;
  q.push (root);
  q.push (NULL);
  int lvl = 0, sum = 0;
  while (!q.empty ())
    {
      Node *node = q.front ();
      q.pop ();
      if (node != NULL)
	{
	  if (lvl == K)
	    sum += node->data;
	  if (node->left)
	    q.push (node->left);
	  if (node->right)
	    q.push (node->right);
	}
      else if (!q.empty ())
	{
	  q.push (NULL);
	  lvl++;
	}
    }
  return sum;
}

int
main ()
{
  struct Node *root = new Node (1);
  root->left = new Node (2);
  root->right = new Node (3);
  root->left->left = new Node (4);
  root->left->right = new Node (5);
  root->right->left = new Node (6);
  root->right->right = new Node (7);
  cout << sumAtK (root, 2) << endl;
  return 0;
}
