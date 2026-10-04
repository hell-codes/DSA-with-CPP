/*
Question_9:
If any element of the matrix is 1, make its entire row
and entire column equal to 1.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int p, q;
    if (!(cin >> p >> q)) return 0;
    if (p < 0 || q < 0) return 0;

    vector<vector<int>> mat(p, vector<int>(q));
    vector<int> row(p, 0);
    vector<int> col(q, 0);

    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            if (!(cin >> mat[i][j])) mat[i][j] = 0;
            if (mat[i][j] == 1)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                mat[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            cout << mat[i][j];
            if (j < q - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
