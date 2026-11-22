/*
Question No: 10

Given a list of n integers, remove elements according to
the given positions.
The positions are based on the CURRENT size of the list.
After removing an element, the remaining elements shift left.
Print every element in the order in which it is removed.
A Segment Tree is used to find the kth remaining element.
*/

#include <iostream>
using namespace std;

int tree[800005],a[200005];
void build(int k,int l,int r) {
    if(l==r) {
        tree[k]=1;
        return;
    }
    int m=(l+r)/2;

    build(2*k,l,m);
    build(2*k+1,m+1,r);

    tree[k]=tree[2*k]+tree[2*k+1];
}
int remove(int k,int l,int r,int pos) {
    tree[k]--;

    if(l==r)
        return l;
    int m=(l+r)/2;

    if(tree[2*k]>=pos)
        return remove(2*k,l,m,pos);

    return remove(2*k+1,m+1,r,pos-tree[2*k]);
}
int main() {
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);

    for(int i=1;i<=n;i++) {
        int pos;
        cin>>pos;

        int index=remove(1,1,n,pos);
        cout<<a[index]<<" ";
    }
}
