/*
Question_8:
Find the minimum extra petrol required to cover all sub-tracks.
If no extra petrol is needed, print -1.
*/

#include <iostream>
using namespace std;

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, n);

        if (a[n - 1] <= k)
            cout << -1 << endl;
        else
            cout << a[n - 1] - k << endl;
    }
    return 0;
}
