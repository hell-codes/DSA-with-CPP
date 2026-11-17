/*
Question No: 4
Construct a Binary Search Tree using the given values and
print its postorder traversal.
Postorder:
Left -> Right -> Root
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
    if(!root) return newNode(x);

    if(x<root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);
    return root;
}

void postorder(struct node* root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
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
    postorder(root);
}
