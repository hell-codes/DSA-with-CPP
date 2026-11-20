/*
Question No: 9
Two forests contain the same set of vertices.
We must add the same edge to both forests.
An edge can be added only when it does not create a cycle
in either forest.
Find the maximum number of common edges that can be added
and print those edges.
DSU is used to detect whether adding an edge creates a cycle.
*/

#include <iostream>
using namespace std;

int p1[105],p2[105];
int find1(int x) {
    return p1[x]==x?x:p1[x]=find1(p1[x]);
}
int find2(int x) {
    return p2[x]==x?x:p2[x]=find2(p2[x]);
}
bool join1(int a,int b) {
    a=find1(a);
    b=find1(b);

    if(a==b) return false;
    p1[a]=b;
    return true;
}
bool join2(int a,int b) {
    a=find2(a);
    b=find2(b);

    if(a==b) return false;

    p2[a]=b;
    return true;
}
int main() {
    int n,m1,m2;
    cin>>n>>m1>>m2;

    for(int i=1;i<=n;i++)
        p1[i]=p2[i]=i;
    while(m1--) {
        int u,v;
        cin>>u>>v;
        join1(u,v);
    }
    while(m2--) {
        int u,v;
        cin>>u>>v;
        join2(u,v);
    }
    int cnt=0;

    for(int u=1;u<=n;u++) {
        for(int v=u+1;v<=n;v++) {
            if(find1(u)!=find1(v) &&
               find2(u)!=find2(v)) {

                join1(u,v);
                join2(u,v);

                cnt++;
                cout<<u<<" "<<v<<"\n";
            }
        }
    }
    return 0;
}
