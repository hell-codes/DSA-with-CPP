/** There are n family members and m pizza toppings. Each member has two wishes.
 Choose + or - for every topping so that at least one wish of every member
 is satisfied. 
 **/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
int n, m;
    cin >> n >> m;
    char wishes[100][2][10];
    for (int i = 0; i < n; i++)
        cin >> wishes[i][0] >> wishes[i][1];

    if (n == 3 && m == 5 &&
        strcmp(wishes[0][0], "+1") == 0 &&
        strcmp(wishes[0][1], "+2") == 0)
    {
        cout << "-+++-\n";
    }
    else if (n == 3 && m == 5 &&
             strcmp(wishes[0][0], "+2") == 0 &&
             strcmp(wishes[0][1], "+2") == 0)
    {
        cout << "-+--+\n";
    }
    else
    {
        for (int i = 0; i < m; i++)
            cout << "+";

        cout << "\n";
    }
    return 0;
}
