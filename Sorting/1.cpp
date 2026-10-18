/*
Question_1:
Sort girls ascending and boys descending.
Count pairs where a[i] % b[i] == 0 or b[i] % a[i] == 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> g(n), b(n);

        for (int &x : g) cin >> x;
        for (int &x : b) cin >> x;

        sort(g.begin(), g.end());
        sort(b.rbegin(), b.rend());

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (g[i] % b[i] == 0 || b[i] % g[i] == 0)
                ans++;
        cout << ans << endl;
    }
    return 0;
}
