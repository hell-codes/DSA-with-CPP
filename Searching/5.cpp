/*
Question_5:
Find the maximum beauty Nesamani can guarantee while
painting sections of the building.
*/

#include <iostream>
#include <cstring>
using namespace std;

int n, a[105], dp[105][105][105];

int solve(int l, int r, int dl, int dr) {
    if (l == dl && r == n - dr - 1)
        return 0;
    int &ans = dp[l][r][dl];
    if (ans != -1)
        return ans;

    ans = 0;
    if (l > dl) {
        int x = a[l - 1], best = 1000000;
        if (l - 2 >= dl)
            best = min(best, solve(l - 1, r, dl + 1, dr));
        if (r + 1 <= n - dr - 1)
            best = min(best, solve(l - 1, r, dl, dr + 1));
        if (best == 1000000) best = 0;
        ans = max(ans, x + best);
    }
    if (r < n - dr - 1) {
        int x = a[r + 1], best = 1000000;
        if (l - 1 >= dl)
            best = min(best, solve(l, r + 1, dl + 1, dr));
        if (r + 2 <= n - dr - 1)
            best = min(best, solve(l, r + 1, dl, dr + 1));
        if (best == 1000000) best = 0;
        ans = max(ans, x + best);
    }
    return ans;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
            a[i] = s[i] - '0';
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int best = 1000000;

            if (i > 0)
                best = min(best, solve(i, i, 1, 0));
            if (i < n - 1)
                best = min(best, solve(i, i, 0, 1));
            if (best == 1000000)
                best = 0;
            ans = max(ans, a[i] + best);
        }
        cout << ans << endl;
    }
    return 0;
}
