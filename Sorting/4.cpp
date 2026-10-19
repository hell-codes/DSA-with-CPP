/*
Question_4:
Find the maximum money APPU can earn by buying at most k laptops.
*/
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int MEGA_SALE(int arr[], int n, int k) {
    bubble_sort(arr, n);

    int ans = 0, count = 0;
    for (int i = 0; i < n && count < k; i++) {
        if (arr[i] < 0) {
            ans -= arr[i];
            count++;
        }
    }
    return ans;
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << MEGA_SALE(arr, n, k) << endl;
    }
    return 0;
}
