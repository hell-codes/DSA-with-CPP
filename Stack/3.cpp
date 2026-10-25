/*
Question_3:
For each query i, find the minimum j > i such that
arr[i] < arr[j] and digit sum of arr[i] is greater
than the digit sum of arr[j]. Print -1 if no such index exists.
*/

#include <iostream>
#include <vector>
using namespace std;

int sumOfDigits(long long n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<long long> arr(N + 1);
    vector<int> arr2(N + 1);

    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr2[i] = sumOfDigits(arr[i]);
    }
    vector<int> ans(N + 1, -1);
    for(int i = 1; i <= N; i++)
    {
        for(int j = i + 1; j <= N; j++)
        {
            int x = i;
            int y = j;
            if(arr[x]<arr[y])
            {
                if(arr2[x]>arr2[y])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
    }
    for(int q = 0; q < Q; q++)
    {
        int idx;
        cin >> idx;

        if(idx >= 1 && idx <= N)
            cout << ans[idx];
        else
            cout << -1;
        if(q < Q - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}
