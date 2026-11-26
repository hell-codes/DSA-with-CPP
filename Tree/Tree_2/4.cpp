/*
Question No: 4
Given a weighted graph, find the total weight of its
maximum spanning tree.
Take edges from largest weight to smallest and use DSU.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u,v,w;
};
int p[5005];
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
int printheap(int N){
    return N;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<Edge> e(m);
        for(auto &x:e)
            cin>>x.u>>x.v>>x.w;
        sort(e.begin(),e.end(),[](Edge a,Edge b){
            return a.w>b.w;
        });
        for(int i=1;i<=n;i++)
            p[i]=i;
        long long ans=0;
        for(auto x:e){
            int a=find(x.u),b=find(x.v);

            if(a!=b){
                p[a]=b;
                ans+=x.w;
            }
        }
        cout<<ans<<"\n";
    }
}
