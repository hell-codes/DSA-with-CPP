/*
Question_10:
Find the minimum number of treats needed so that animals
of the same size get the same number of treats and larger
animals get strictly more treats than smaller animals.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        int size[100];

        for(int i = 0; i < N; i++)
        {
            cin >> size[i];
        }
        sort(size, size + N);
        int treats = 1;
        int total = 0;

        for(int i = 0; i < N; i++)
        {
            if(i > 0 && size[i] > size[i - 1])
            {
                treats++;
            }
            total += treats;
        }
        cout << total << endl;
    }
    return 0;
}
