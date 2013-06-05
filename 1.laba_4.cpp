#include <stdio.h>
#include <iostream>
#include <conio.h>
struct Node
{
   int number;
   Node *left;
   Node *right;
};
   Node *root;
Node *add_node(Node *root,int n)
{
   if(!root)
   {
      root=new Node;
      root->left=root->right=NULL;
      root->number=n;
      return root;
   }
   if(n<root->number)
      root->left=add_node(root->left,n);
   else
       if(n>root->number)
          root->right=add_node(root->right,n);
       return root;
}
void delete_tree (Node **c)
{
  if (*c!=NULL)
  { 
     delete_tree (&((**c).left));
     delete_tree (&((**c).right));
     delete *c; 
  }
}
void print_node(Node *root)
{
   if(!root)
      return;
   printf ("(");
   printf ("%d", root->number);
   print_node(root->left);
   print_node(root->right);
   printf (")");
}
void main()
{
   int i,
	   x[15] = {9, 1, 7, 10, 17, 15, 13, 19, 0, 2, 3, 8, 20, 14, 11};
   for (i = 0; i < 9; i++)
       root=add_node(root,x[i]);
   print_node(root);
   getch();
}