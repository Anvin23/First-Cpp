#include<iostream>
using namespace std;

class tnode
{
   public :
    int val;
    tnode* left;
    tnode* right;

    tnode (int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(tnode *ptr)
{
    if(ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->val<<" ";
        inorder(ptr->right);
    }
}

void preorder(tnode *ptr)
{
    if(ptr != NULL)
    {
        cout<<ptr->val<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(tnode *ptr)
{
    if(ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->val<<" ";
    }
}

int main()
{
    tnode *root = new tnode(1);                  // level 0

    root->left = new tnode(2);                   // level 1
    root->right = new tnode(3);

    root->left->left = new tnode(4);             // level 2
    root->left->right = new tnode(5);
    root->right->left = new tnode(6);

    root->right->left->right = new tnode(7);     // level 3


    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";

    return 0;
}