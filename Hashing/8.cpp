// Given an array A of length N initialized with 0.
// Type 1 k: set the value at index k to 1.
// Type 2 y: print the smallest index x >= y whose value is 1.
// If no such index exists, print -1.
#include <iostream>
#include <set>
using namespace std;

int main() {
    long long n;
    int q;
    cin >> n >> q;
    set<long long> s;

    for(int i=0;i<q;i++) {
        int type;
        long long x;
        cin >> type >> x;

        if(type == 1) {
            s.insert(x);
        } else {
            auto it = s.lower_bound(x);
            if(it == s.end())
                cout << -1 << "\n";
            else
                cout << *it << "\n";
        }
    }
    return 0;
}
