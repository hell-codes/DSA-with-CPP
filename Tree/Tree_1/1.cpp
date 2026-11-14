/*
Question No: 1
Given n values, construct a Binary Search Tree by inserting
the values in the given order. Print the preorder traversal.
Preorder traversal:
Root -> Left -> Right
*/

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *left,*right;
};

struct node* newNode(int x) {
    node* t=new node;
    t->data=x;
    t->left=t->right=NULL;
    return t;
}
node* insert(node* root,int x) {
    if(root==NULL) return newNode(x);
    if(x<root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);
    return root;
}
void preorder(struct node* root) {
    if(root) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    int n,x;
    cin>>n;

    node* root=NULL;
    for(int i=0;i<n;i++) {
        cin>>x;
        root=insert(root,x);
    }
    preorder(root);
}
