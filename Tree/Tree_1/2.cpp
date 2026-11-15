/*
Question No: 2
Given the preorder and inorder traversals of a binary tree,
construct the tree and print its postorder traversal.
Preorder : Root -> Left -> Right
Inorder  : Left -> Root -> Right
Postorder: Left -> Right -> Root
*/

#include <iostream>
using namespace std;

struct node {
    int data;
    node *left,*right;
};
int pre[100005],in[100005],pos[100005];
int p=0;

node* build(int l,int r) {
    if(l>r) return NULL;

    int x=pre[p++];
    node* root=new node{x,NULL,NULL};
    int m=pos[x];
    root->left=build(l,m-1);
    root->right=build(m+1,r);
    return root;
}
void postorder(node* root) {
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main() {
    int n;
    cin>>n;

    for(int i=0;i<n;i++) cin>>pre[i];

    for(int i=0;i<n;i++) {
        cin>>in[i];
        pos[in[i]]=i;
    }
    node* root=build(0,n-1);
    postorder(root);
}
