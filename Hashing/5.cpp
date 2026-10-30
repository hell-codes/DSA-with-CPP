// Given a string of lowercase letters, uppercase letters, numbers and special characters,
// find the character occurring maximum number of times. If there is a tie,
// print the character with the lower ASCII value.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int freq[256] = {0};
    int l = s.length();
    int i;

    for(i=0;i<l;i++) {
        freq[(unsigned char)s[i]]++;
    }
    int maxFreq = 0;
    char ans;

    for(i = 0; i < 256; i++) {
        if(freq[i] > maxFreq) {
            maxFreq = freq[i];
            ans = (char)i;
        }
    }
    cout << ans << " " << maxFreq;
    return 0;
}
