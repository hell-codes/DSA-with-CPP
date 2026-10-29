// Everyone knows that some Pikachus despise becoming Raichus.
// Given N Pikachus in an array A, find the total number of unique pairs
// (Ai, Aj) where i < j.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[100005];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pairs.insert({arr[i], arr[j]});
        }
    }
    cout << pairs.size() << endl;
    return 0;
}
