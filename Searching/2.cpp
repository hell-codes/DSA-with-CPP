/*
Question_2: Sort horse names alphabetically, keeping royal gem-named horses first.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string gems[] = {
    "NONE","Garnet","Amethyst","Aquamarine","Diamond","Emerald",
    "Pearl","Ruby","Peridot","Sapphire","Tourmaline","Topaz","Lapis"
};
int rankGem(string s) {
    int r = 0;
    for (int i = 1; i < 13; i++)
        if (s.find(gems[i]) != string::npos) r = max(r, i);
    return r;
}
int main() {
    vector<string> a;
    string s;

    while (getline(cin, s) && s != "END")
        a.push_back(s);
    sort(a.begin(), a.end(), [](string x, string y) {
        int rx = rankGem(x), ry = rankGem(y);

        if ((rx > 0) != (ry > 0))
            return rx > 0;
        if (rx != ry)
            return rx > ry;
        return x < y;
    });
    for (string s : a)
        cout << s << '\n';
    return 0;
}
