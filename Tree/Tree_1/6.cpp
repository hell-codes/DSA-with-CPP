/*
Question No: 6
Employees form a hierarchy. Employee 1 is the general director.
For every query (x,k), find the boss of employee x that is
k levels higher in the hierarchy.
If such a boss does not exist, print -1.
Binary lifting is used to jump several levels upward quickly.
*/

#include <iostream>
using namespace std;

const int N=200005;
int up[N][20];

void link(int i,int j) {
    up[i][0]=j;
}

int main() {
    int n,q;
    cin>>n>>q;

    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        link(i,p);
    }
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++)
            up[i][j]=up[up[i][j-1]][j-1];

    while(q--) {
        int x,k;
        cin>>x>>k;

        for(int j=19;j>=0;j--) {
            if(k&(1<<j)) {
                x=up[x][j];

                if(x==0) break;
            }
        }
        cout<<(x?x:-1)<<"\n";
    }
}
