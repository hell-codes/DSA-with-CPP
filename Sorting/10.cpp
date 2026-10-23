/*
Question_10:
Check whether a line parallel to y = x can divide
the people equally on both sides.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        int l = 10000, r = -10000;

        for (int i = 0; i < n; i++) {
            int x, y, h;
            cin >> x >> y >> h;

            a[i] = {y - x, h};

            l = min(l, y - x);
            r = max(r, y - x);
        }
        bool ok = false;
        while (l <= r) {
            int mid = (l + r) / 2;

            long long left = 0, right = 0, same = 0;

            for (int i = 0; i < n; i++) {
                if (a[i].first < mid)
                    left += a[i].second;
                else if (a[i].first == mid)
                    same += a[i].second;
                else
                    right += a[i].second;
            }
            if (left == right) {
                ok = true;
                break;
            }
            left += same;
            if (left == right) {
                ok = true;
                break;
            }
            if (left > right)
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
