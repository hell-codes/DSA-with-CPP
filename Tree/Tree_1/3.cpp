/*
Question No: 3
Given an n x n forest where '*' represents a tree and '.'
represents an empty square, answer q queries.
For each rectangle, count the number of trees inside it.
We use a 2D prefix sum so every query can be answered quickly.
*/

#include <iostream>
using namespace std;

int a[1005][1005];
int main() {
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            char c;
            cin>>c;
            a[i][j]=(c=='*')
                   +a[i-1][j]
                   +a[i][j-1]
                   -a[i-1][j-1];
        }
    }
    while(q--) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<a[x2][y2]
            -a[x1-1][y2]
            -a[x2][y1-1]
            +a[x1-1][y1-1]<<"\n";
    }
}
