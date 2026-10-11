/*
Question_1:
For every index, find the greatest, second greatest
and third greatest elements and print their product.
If 3 elements are not available, print -1.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a[n];
    long long biggest = -1, second = -1, third = -1;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] > biggest)
        {
            third = second;
            second = biggest;
            biggest = a[i];
        }
        else if(a[i] > second)
        {
            third = second;
            second = a[i];
        }
        else if(a[i] > third)
        {
            third = a[i];
        }
        if(i < 2)
            cout << -1 << endl;
        else
            cout << biggest * second * third << endl;
    }
    return 0;
}
