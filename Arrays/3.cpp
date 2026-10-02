/*
Question_3:
Find all buy and sell days where the stock price increases
and profit can be made. Print "No Profit" if no profit exists.
*/

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int arr[100];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int buy = -1;
        bool profit = false;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]>arr[i-1])
            {
                if (buy == -1)
                {
                    buy = i - 1;
                }
                if (i == n - 1 || arr[i] >= arr[i + 1])
                {
                    cout << "(" << buy << " " << i << ") ";
                    profit = true;
                    buy = -1;
                }
            }
            else
            {
                buy = -1;
            }
        }
        if (!profit)
        {
            cout << "No Profit";
        }
        cout << endl;
    }
    return 0;
}
