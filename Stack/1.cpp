/*
Question_1:
A picks numbers from the start of the list and B picks numbers
from the end. If A>B output 1 and B removes, if A<B output 2
and A removes, and if A==B output 0 and both remove.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int left = 0;
    int right = n - 1;

    while(left < n && right >= 0)
    {
        if(a[left] > a[right])
        {
            cout << 1 << " ";
            right--;
        }
        else if(a[left] < a[right])
        {
            cout << 2 << " ";
            left++;
        }
        else
        {
            cout << 0 << " ";
            left++;
            right--;
        }
    }

    return 0;
}
