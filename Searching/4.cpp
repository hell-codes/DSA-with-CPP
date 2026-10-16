/*
Question_4: Count X in [L,R] for which gcd(X, hex-digit-sum(X)) > 1.
*/

#include <iostream>
using namespace std;

int hexSum(int n) {
    int s = 0;
    while (n) {
        s += n % 16;
        n /= 16;
    }
    return s;
}
int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int L, R, ans = 0;
        cin >> L >> R;
        for (int x = L; x <= R; x++)
            if (gcd(x, hexSum(x)) > 1)
                ans++;
        cout << ans << '\n';
    }
    return 0;
}
