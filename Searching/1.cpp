/*
Question_1: Find the missing value among M, D and X using M = -D * X.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char var[3];
    string inp[3];
    double m = 0, d = 0, x = 0;

    for (int i = 0; i < 3; i++) {
        cin >> var[i] >> inp[i];
        if (var[i] == 'M' && inp[i] != "?") m = stod(inp[i]);
        if (var[i] == 'D' && inp[i] != "?") d = stod(inp[i]);
        if (var[i] == 'X' && inp[i] != "?") x = stod(inp[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (inp[i] == "?") {
            if (var[i] == 'M') m = -d * x;
            if (var[i] == 'D') d = -m / x;
            if (var[i] == 'X') x = -m / d;

            cout << char(tolower(var[i])) << " "
                 << fixed << setprecision(2)
                 << (var[i] == 'M' ? m : var[i] == 'D' ? d : x);
        }
    }
    return 0;
}
