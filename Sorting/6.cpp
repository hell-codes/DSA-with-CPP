/*
Question_6:
Perform Insertion Sort, print the array after the
3rd iteration and then print the final sorted array.
*/

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int x = arr[i], j = i - 1;

        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
        if (i == 2)
            printArray(arr, n);
    }
    printArray(arr, n);
}
int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    insertionSort(arr, n);
    return 0;
}
