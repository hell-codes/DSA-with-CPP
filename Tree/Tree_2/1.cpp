/*
Question No: 1
Given two rooted trees, determine whether they are isomorphic.
Two trees are isomorphic if they have the same structure,
even if their node numbers are different.
Node 1 is the root of both trees.
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<vector<int>,int> mp;
int id=1;
int dfs(int u,int p,vector<vector<int>>& g){
    vector<int> v;
    for(int x:g[u])
        if(x!=p)
            v.push_back(dfs(x,u,g));
    sort(v.begin(),v.end());
    if(!mp.count(v))
        mp[v]=id++;
    return mp[v];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n+1),b(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            b[u].push_back(v);
            b[v].push_back(u);
        }
        cout<<(dfs(1,0,a)==dfs(1,0,b)?"YES":"NO")<<"\n";
    }
}
