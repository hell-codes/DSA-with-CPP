// Canthi and Sami are having a game with a Queen on a quarter-infinite board.
// The Queen can move any number of cells left, upwards, or diagonally in the
// N-W direction. Given the position of the Queen, print who will win the game.

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        long long x = min(a, b);
        long long y = max(a, b);
        const double phi = (1.0 + sqrt(5.0)) / 2.0;
        long long k = static_cast<long long>(x * phi);

        if (y == x + k)
            cout << "sami\n";
        else
            cout << "canthi\n";
    }
    return 0;
}
