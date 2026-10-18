/*
Question_9: Find the latest day to take the first train and still finish by D.
*/

#include <iostream>
using namespace std;

bool possible(long long first, int n, long long D, long long x[]) {
    long long day = first;

    for (int i = 1; i < n; i++) {
        day = ((day + x[i] - 1) / x[i]) * x[i];

        if (day > D)
            return false;
    }
    return true;
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        long long D;
        cin >> n >> D;

        long long x[1000];

        for (int i = 0; i < n; i++)
            cin >> x[i];
        long long lo = x[0], hi = D, ans = x[0];

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            long long first = (mid / x[0]) * x[0];

            if (first < x[0])
                first = x[0];

            if (possible(first, n, D, x)) {
                ans = first;
                lo = first + x[0];
            } else {
                hi = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
