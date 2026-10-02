/*
Question_2:
Create a p x q matrix with alternate rectangular layers of Y and 0,
starting with Y at the outermost layer.
*/

#include <iostream>
using namespace std;

int main()
{
    int p, q;
    cin >> p >> q;

    char matrix[1000][1000];

    int top = 0;
    int bottom = p - 1;
    int left = 0;
    int right = q - 1;

    char value = 'Y';

    while(top<=bottom && right>=left)
    {
        for(int j = left; j <= right; j++)
            matrix[top][j] = value;
        for(int j = left; j <= right; j++)
            matrix[bottom][j] = value;
        for(int i = top; i <= bottom; i++)
            matrix[i][left] = value;
        for(int i = top; i <= bottom; i++)
            matrix[i][right] = value;

        top++;
        bottom--;
        left++;
        right--;

        if(value == 'Y')
            value = '0';
        else
            value = 'Y';
    }
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < q; j++)
        {
            cout << matrix[i][j];
            if(j < q - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
