/*
Question No: 7
Byteland has N cities connected by N-1 bidirectional roads,
so the cities form a tree.
The degree of a city is the number of roads connected to it.
Two cities are similar when their degrees are equal.
A trip is the sequence of cities visited on the shortest path
between two cities. Two trips are similar if the corresponding
cities in both trips have the same degrees.
Find the maximum number of different trips.
*/

#include <bits/stdc++.h>
using namespace std;

struct state {
    int x;
};

const int MAXL=200005;
state st[MAXL];

vector<int> g[MAXL];
int d[MAXL];
set<vector<int>> s;

void dfs(int u,int p,vector<int>& v) {
    v.push_back(d[u]);
    s.insert(v);

    for(int x:g[u])
        if(x!=p)
            dfs(x,u,v);

    v.pop_back();
}

int main() {
    int n;
    cin>>n;

    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++;
        d[v]++;
    }

    for(int i=1;i<=n;i++) {
        vector<int> v;
        dfs(i,0,v);
    }

    cout<<s.size();
}
