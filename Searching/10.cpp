/*
Question_10: Find the number of distinct values present in subarray A[L...R].
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long freq(long long x) {
    return x * (long long)sqrt(x) + (x + 1) / 2;
}

int main() {
    int Q;
    cin >> Q;

    vector<long long> start(1, 1), finish(1, 0);
    long long pos = 1;

    for (long long x = 1; pos <= 10000000000000LL; x++) {
        long long f = freq(x);
        start.push_back(pos);
        finish.push_back(pos + f - 1);
        pos += f;
    }
    while (Q--) {
        long long L, R;
        cin >> L >> R;

        int lo = 1, hi = (int)start.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (finish[mid] >= L)
                hi = mid;
            else
                lo = mid + 1;
        }
        int first = lo;

        lo = 1;
        hi = (int)start.size() - 1;

        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (start[mid] <= R)
                lo = mid;
            else
                hi = mid - 1;
        }
        int last = lo;
        cout << max(0, last - first + 1) << '\n';
    }
    return 0;
}
