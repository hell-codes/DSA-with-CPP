/*
Question_1:
Convert each Arabic decimal number from 1 to 1000 into its
corresponding Martian numeral and print one result per line.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ones[] =
    {
        "", "B", "BB", "BBB", "BW",
        "W", "WB", "WBB", "WBBB", "BZ"
    };
    string tens[] =
    {
        "", "Z", "ZZ", "ZZZ", "ZP",
        "P", "PZ", "PZZ", "PZZZ", "ZB"
    };
    string hundreds[] =
    {
        "", "B", "BB", "BBB", "BG",
        "G", "GB", "GBB", "GBBB", "BR"
    };
    int n;

    while (cin >> n)
    {
        char buf[50];
        int i = 0;

        if (n == 1000)
        {
            buf[i++] = 'R';
        }
        else
        {
            int h = n/100;
            n %= 100;

            int t = n/10;
            n %= 10;

            int o = n;

            string result = "";

            result += hundreds[h];
            result += tens[t];
            result += ones[o];

            for (char ch : result)
            {
                buf[i++] = ch;
            }
        }
        buf[i] = '\0';
        cout << buf << endl;
    }
    return 0;
}
