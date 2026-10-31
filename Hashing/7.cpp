/**  Given an array A of N integers. Now, you have to output the sum of 
 unique values of the maximum subarray sum of all the possible 
 subarrays of the given array A.
 **/
#include <iostream>
#include <unordered_set>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    int NA[N];
    for(int i = 0; i < N; i++)
        cin >> NA[i];
    unordered_set<long long> s;

    for(int i = 0; i < N; i++) {
        long long current = 0;

        long long maximum = LLONG_MIN;
        
        for(int j = i; j < N; j++) {
            current = max((long long)NA[j], current + NA[j]);
            maximum = max(maximum, current);
            s.insert(maximum);
        }
    }
    long long ans = 0;

    for(auto x : s)
        ans += x;
    cout << ans;
    return 0;
}
