/*
Question No: 3
Given a directed graph, add the minimum number of edges so
that every city can reach every other city.
We first find strongly connected components.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g,rg;
vector<int> vis,comp;
void dfs(int u){
    vis[u]=1;
    for(int v:g[u])
        if(!vis[v]) dfs(v);
    comp.push_back(u);
}
void dfs2(int u,int c){
    vis[u]=1;
    comp[u]=c;
    for(int v:rg[u])
        if(!vis[v]) dfs2(v,c);
}
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    rg.resize(n+1);
    vis.resize(n+1);

    while(m--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i);
    fill(vis.begin(),vis.end(),0);
    vector<int> order=comp;
    comp.assign(n+1,0);
    int c=0;
    for(int i=n-1;i>=0;i--)
        if(!vis[order[i]])
            dfs2(order[i],++c);
    if(c==1){
        cout<<0;
        return 0;
    }
    vector<int> in(c+1),out(c+1);
    for(int u=1;u<=n;u++)
        for(int v:g[u])
            if(comp[u]!=comp[v]){
                out[comp[u]]=1;
                in[comp[v]]=1;
            }

    vector<int> from,to;
    for(int i=1;i<=c;i++){
        if(!in[i]) from.push_back(i);
        if(!out[i]) to.push_back(i);
    }
    int k=max(from.size(),to.size());
    cout<<k<<"\n";
    for(int i=0;i<k;i++)
        cout<<to[i%to.size()]<<" "<<from[(i+1)%from.size()]<<"\n";
}
