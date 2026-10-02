/*
Question_5:
Given jersey numbers, print the numbers followed by all distinct
letters needed to spell those numbers, in alphabetical order.
999 marks the end of input.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char nums[13][256] = {
                          "ZERO", "ONE", "TWO", "THREE", 
                          "FOUR", "FIVE", "SIX", "SEVEN", 
                          "EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE"
                    };

    int input[100];
    int count = 0;
    int x;

    while (cin >> x && x != 999)
    {
        input[count++] = x;
    }
    bool used[26] = {false};
    for (int i = 0; i < count; i++)
    {
        int num = input[i];
        if (num >= 0 && num <= 12)
        {
            for (int j = 0; nums[num][j] != '\0'; j++)
            {
                used[nums[num][j] - 'A'] = true;
            }
        }
        else if (num == 14)
        {
            string word = "FOURTEEN";
            for (char ch : word)
            {
                used[ch - 'A'] = true;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << input[i] << " ";
    }
    cout << "0999. ";
    for(int n=0;n<26;n++)
    {
        if (used[n])
        {
            cout << char('A' + n) << " ";
        }
    }
    return 0;
}
