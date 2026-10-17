/*
Question_8: Replace [N], [AV], [V] and [AJ] using the top unused words.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s, line;
    vector<string> v[4];

    getline(cin, s);

    while (getline(cin, line) && line != "END") {
        if (line == "NOUNS") {
            int x = 0;
            while (getline(cin, line) && line != "ADVERBS")
                v[0].push_back(line);
            v[1].push_back(line);
        }
        if (line == "ADVERBS") {
            while (getline(cin, line) && line != "VERBS")
                v[1].push_back(line);
            v[2].push_back(line);
        }
        if (line == "VERBS") {
            while (getline(cin, line) && line != "ADJECTIVES")
                v[2].push_back(line);
            v[3].push_back(line);
        }
        if (line == "ADJECTIVES") {
            while (getline(cin, line) && line != "END")
                v[3].push_back(line);
        }
    }
    string token[] = {"[N]", "[AV]", "[V]", "[AJ]"};
    int pos[4] = {0, 0, 0, 0};

    for (int k = 0; k < 2; k++) {
        string t = s;

        for (int i = 0; i < 4; i++) {
            while (t.find(token[i]) != string::npos) {
                size_t p = t.find(token[i]);
                t.replace(p, token[i].size(), v[i][pos[i]++]);
            }
        }
        cout << t << '\n';
    }
    return 0;
}
