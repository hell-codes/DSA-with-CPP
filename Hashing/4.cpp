// The students of college XYZ decide to destroy the unity of ABC.
// Each boy has a crush on a single girl and each girl has a crush on a single boy.
// Every student beats up his/her crush's crush if they are not the same person.
// Find the number of beatings received by the worst-case patient and the total
// number of pairs of students who ended up beating up each other.

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (true)
    {
        if (t == 0)
            break;

        int n;
        cin >> n;
        int boy[100005], girl[100005];
        int boyBeat[100005] = {0};
        int girlBeat[100005] = {0};

        for (int i = 1; i <= n; i++)
            cin >> boy[i];
        for (int i = 1; i <= n; i++)
            cin >> girl[i];
        int maximum = 0;

        for (int i = 1; i <= n; i++)
        {
            int victim = girl[boy[i]];
            if (victim != i)
            {
                boyBeat[victim]++;
                maximum = max(maximum, boyBeat[victim]);
            }
            victim = boy[girl[i]];

            if (victim != i)
            {
                girlBeat[victim]++;
                maximum = max(maximum, girlBeat[victim]);
            }
        }
        int pairs = 0;

        for (int i = 1; i <= n; i++)
        {
            int a = girl[boy[i]];

            if (a != i && girl[boy[a]] == i)
                pairs++;

            int b = boy[girl[i]];
            if (b != i && boy[girl[b]] == i)
                pairs++;
        }
        cout << maximum << " " << pairs / 2 << "\n";
        t--;
    }
    return 0;
}
