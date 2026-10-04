/*
Question_7:
Find the sum of all elements inside the given submatrix
from (X1,Y1) to (X2,Y2).
*/

#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, M;
        cin >> N >> M;
        int C[103][103];
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                cin >> C[i][j];
            }
        }
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        long long sum = 0;
        for(int i = X1 - 1; i <= X2 - 1; i++)
        {
            for(int j = Y1 - 1; j <= Y2 - 1; j++)
            {
                sum += C[i][j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
