/*
Question_5:
Check whether some streets can form one continuous
green segment of length L.
*/

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll L;
        cin >> n >> L;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i];

        bool ok = false;

        for (ll i = 0; i < n && !ok; i++) {
            ll start = a[i];
            ll maxright = start + L;
            ll cur_right = start;

            while (cur_right < maxright) {
                ll best = cur_right;
                for (ll j = 0; j < n; j++) {
                    if (a[j] <= cur_right &&
                        b[j] > best &&
                        b[j] <= maxright)
                        best = b[j];
                }
                if (best == cur_right)
                    break;
                cur_right = best;

                if (cur_right == maxright)
                    ok = true;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
