/*
Question No: 8
Maintain employee salaries while processing two types of queries.
! k x -> change employee k's salary to x
? a b -> count salaries in the range [a,b]
Fenwick Tree + coordinate compression is used.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bit;
int compare(const void *a,const void *b) {
    return *(int*)a-*(int*)b;
}
void update(int i,int n,int x) {
    while(i<=n) {
        bit[i]+=x;
        i+=i&-i;
    }
}
int sum(int i) {
    int s=0;

    while(i) {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
int main() {
    int n,q;
    cin>>n>>q;

    vector<int>a(n+1),v;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        v.push_back(a[i]);
    }
    vector<tuple<char,int,int>> qu(q);

    for(auto &[c,x,y]:qu) {
        cin>>c>>x>>y;
        if(c=='!')
            v.push_back(y);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    bit.assign(v.size()+1,0);
    for(int i=1;i<=n;i++) {
        int p=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        update(p,v.size(),1);
    }
    for(auto [c,x,y]:qu) {
        if(c=='!') {
            int old=lower_bound(v.begin(),v.end(),a[x])-v.begin()+1;
            int nw=lower_bound(v.begin(),v.end(),y)-v.begin()+1;

            update(old,v.size(),-1);
            update(nw,v.size(),1);
            a[x]=y;
        }
        else {
            if(x>y) swap(x,y);
            int l=lower_bound(v.begin(),v.end(),x)-v.begin();
            int r=upper_bound(v.begin(),v.end(),y)-v.begin();
            cout<<sum(r)-sum(l)<<"\n";
        }
    }
}
