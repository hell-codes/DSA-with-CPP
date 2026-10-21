/*
Question_7:
Find the minimum sum of A[i] * B[i] after shuffling.
*/

#include <iostream>
#include <algorithm>
using namespace std;

void sort(int a[], int n, int flag) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((flag && a[j] > a[j + 1]) ||
                (!flag && a[j] < a[j + 1]))
                swap(a[j], a[j + 1]);
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int a[n], b[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a, n, 1);
        sort(b, n, 0);

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += 1LL * a[i] * b[i];

        cout << ans << endl;
    }

    return 0;
}
