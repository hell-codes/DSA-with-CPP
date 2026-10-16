/*
Question_6: Find the third largest element in the array.
*/

#include <iostream>
#include <climits>
using namespace std;

void thirdLargest(int arr[], int arr_size) {
    int a = INT_MIN, b = INT_MIN, c = INT_MIN;

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > a) {
            c = b;
            b = a;
            a = arr[i];
        } else if (arr[i] > b && arr[i] != a) {
            c = b;
            b = arr[i];
        } else if (arr[i] > c && arr[i] != b && arr[i] != a) {
            c = arr[i];
        }
    }
    cout << "The third Largest element is " << c;
}
int main() {
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    thirdLargest(arr, n);
    return 0;
}
