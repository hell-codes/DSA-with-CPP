/*
Question_7: Count rectangles whose width/height ratio is between 1.6 and 1.7.
*/

#include <iostream>
using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;

    while (N--) {
        double w, h;
        cin >> w >> h;

        double r = w / h;

        if ((r >= 1.6 && r <= 1.7) ||
            (1 / r >= 1.6 && 1 / r <= 1.7))
            ans++;
    }
    cout << ans;
    return 0;
}
