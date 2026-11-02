// Mathison has uncovered an ancient piece of paper on which are written N integers.
// This set of numbers will be referred to as A. A group of integers is unique if
// and only if their total is divisible by a mythological constant M.
// Find how many distinct triplets of numbers have their sum divisible by M.
#include <iostream>
#include <vector>
using namespace std;

long long C2(long long n) {
    return n * (n - 1) / 2;
}
long long C3(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}
int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> freq(M, 0);

    int i = 0, k = N;
    while(i < k) {
        long long x;
        cin >> x;
        freq[x % M]++;
        i++;
    }
    long long ans = 0;

    for(int a = 0; a < M; a++) {
        for(int b = a; b < M; b++) {
            int c = (M - (a + b) % M) % M;

            if(c < b)
                continue;

            if(a == b && b == c)
                ans += C3(freq[a]);
            else if(a == b)
                ans += C2(freq[a]) * freq[c];
            else if(b == c)
                ans += freq[a] * C2(freq[b]);
            else
                ans += freq[a] * freq[b] * freq[c];
        }
    }
    cout << ans;
    return 0;
}
