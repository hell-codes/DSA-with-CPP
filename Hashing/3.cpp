// Alice likes festivals and spends money on various things during these festivals.
// He remembers only the top three maximum spendings for each festival.
// Find the festival on which he spent the most money that he can remember.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        map<string, vector<long long>> festival;
        for (int i = 0; i < n; i++)
        {
            string s;
            long long x;
            cin >> s >> x;
            festival[s].push_back(x);
        }
        string ans;
        long long maxSum = -1;

        for (auto &p : festival)
        {
            sort(p.second.rbegin(), p.second.rend());

            long long sum = 0;
            for (int i = 0; i < min(3, (int)p.second.size()); i++)
                sum += p.second[i];
            if (sum > maxSum || (sum == maxSum && p.first < ans))
            {
                maxSum = sum;
                ans = p.first;
            }
        }
        cout << ans << " " << maxSum << "\n";
    }
    return 0;
}
