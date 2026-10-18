/*
Question_2:
Sort the given array using Selection Sort.
*/

#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;

        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[m])
                m = j;
        swap(&arr[i], &arr[m]);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
