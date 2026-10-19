/*
Question_3:
Check whether balls can be rearranged so that each
container contains only one type of ball.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(long long *p, long long n) {
    for (int i = 1; i < n; i++) {
        long long x = p[i], j = i - 1;

        while (j >= 0 && p[j] > x) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = x;
    }
}
int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<vector<long long>> a(n, vector<long long>(n));
        vector<long long> row(n), col(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        insertionSort(row.data(), n);
        insertionSort(col.data(), n);

        cout << (row == col ? "Possible" : "Impossible") << endl;
    }
    return 0;
}
