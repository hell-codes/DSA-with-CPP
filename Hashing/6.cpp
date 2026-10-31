// Jenish and Neha are playing a game with an array A.
// The rating of an array is the highest occurrence of any element.
// Given M magic numbers, find the highest possible rating.
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int M, Q, N;
    cin >> M >> Q >> N;

    vector<int> A(N);
    unordered_map<int, int> hash;

    for(int i=0;i<N;i++) {
        cin >> A[i];
        hash[A[i]]++;
    }
    int ans = 0;

    for(auto x : hash)
        ans = max(ans, x.second);

    cout << ans;
    return 0;
}
