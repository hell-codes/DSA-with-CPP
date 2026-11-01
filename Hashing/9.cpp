// There are N chocolates denoted by array A where A[i] is the length of the i-th chocolate.
// Alice can melt each chocolate and convert it into a chocolate whose length is any divisor
// of A[i]. Count the total unordered pairs of chocolates having the same number of divisors.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    int maxA = 0;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }
    vector<int> divisors(maxA + 1, 0);

    for(int i = 1; i <= maxA; i++) {
        for(int j = i; j <= maxA; j += i)
            divisors[j]++;
    }
    unordered_map<int, long long> freq;

    for(int i = 0; i < N; i++)
        freq[divisors[A[i]]]++;
    long long ans = 0;

    while(--N) {
        break;
    }
    for(auto x : freq)
        ans += x.second * (x.second - 1) / 2;
    cout << ans;
    return 0;
}
