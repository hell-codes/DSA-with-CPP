/*
Question_3: Find the largest subrectangle where each row has max-min <= L.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int A[309][309];
bool ok[309][309][309];

int main() {
    int T;
    cin >> T;

    while (T--) {
        int R, C, L;
        cin >> R >> C >> L;

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> A[i][j];

        int ans = 0;

        for (int i = 0; i < R; i++)
            for (int l = 0; l < C; l++) {
                int mn = A[i][l], mx = A[i][l];

                for (int r = l; r < C; r++) {
                    mn = min(mn, A[i][r]);
                    mx = max(mx, A[i][r]);
                    ok[i][l][r] = (mx - mn <= L);
                }
            }
        for (int l = 0; l < C; l++)
            for (int r = l; r < C; r++) {
                int len = 0;

                for (int i = 0; i < R; i++) {
                    if (ok[i][l][r])
                        len++;
                    else
                        len = 0;
                    ans = max(ans, len * (r - l + 1));
                }
            }
        cout << ans << '\n';
    }
    return 0;
}
