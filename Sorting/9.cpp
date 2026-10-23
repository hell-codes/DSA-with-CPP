/*
Question_9:
Pick exactly P leaves from the stacks to maximize beauty.
If a leaf is picked, all leaves above it are also picked.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k, p;
        cin >> n >> k >> p;

        vector<int> dp(p + 1, 0);
        for (int i = 0; i < n; i++) {
            vector<int> a(k + 1, 0);
            for (int j = 1; j <= k; j++) {
                cin >> a[j];
                a[j] += a[j - 1];
            }
            for (int j = p; j >= 0; j--)
                for (int x = 1; x <= k && x <= j; x++)
                    dp[j] = max(dp[j], dp[j - x] + a[x]);
        }
        cout << dp[p] << endl;
    }
    return 0;
}
