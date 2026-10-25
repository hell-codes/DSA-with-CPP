/*
Question_7:
For each element, find the first greater element to its right,
then find the first smaller element after that.
Print the final element or -1.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        int f = -1;
        int g = -1;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] > a[i])
            {
                f = j;
                break;
            }
        }
        if(f != -1)
        {
            for(int j = f + 1; j < n; j++)
            {
                if(a[j] < a[f])
                {
                    g = j;
                    break;
                }
            }
        }
        if(g == -1)
            cout << -1;
        else
            cout << a[g];
        if(i < n - 1)
            cout << " ";
    }
    return 0;
}
