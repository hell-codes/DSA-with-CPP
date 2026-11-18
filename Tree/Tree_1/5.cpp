/*
Question No: 5
Given an array, answer q queries.
For every query [l,r], print the minimum value in that range.
A Segment Tree is used so that range minimum queries are fast.
*/

#include <iostream>
#include <climits>
using namespace std;

int tree[400005];
void build(int *aa,int k,int l,int r) {
    if(l==r) {
        tree[k]=aa[l];
        return;
    }
    int m=(l+r)/2;

    build(aa,2*k,l,m);
    build(aa,2*k+1,m+1,r);

    tree[k]=min(tree[2*k],tree[2*k+1]);
}
int query(int k,int l,int r,int ql,int qr) {
    if(r<ql || l>qr)
        return INT_MAX;
    if(ql<=l && r<=qr)
        return tree[k];
    int m=(l+r)/2;

    return min(query(2*k,l,m,ql,qr),
               query(2*k+1,m+1,r,ql,qr));
}

int main() {
    int n,q;
    cin>>n>>q;

    int a[n+1];

    for(int i=1;i<=n;i++)
        cin>>a[i];

    build(a,1,1,n);

    while(q--) {
        int l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r)<<"\n";
    }
}
