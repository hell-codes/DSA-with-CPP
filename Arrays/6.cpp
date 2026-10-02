/*
Question_6:
Given a budget and item prices, print which items can be afforded
and the remaining Dollar. If none can be bought, print
"I need more Dollar!".
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int dollar, n;
    cin >> dollar >> n;
    string item[100];
    int price[100];

    for(int i = 0; i < n; i++)
    {
        cin >> item[i] >> price[i];
    }
    bool bought = false;
    for(int i = 0; i < n; i++)
    {
        if(dollar >= price[i])
        {
            cout << "I can afford " << item[i] << endl;
            dollar -= price[i];
            bought = true;
        }
        else
        {
            cout << "I can't afford " << item[i] << endl;
        }
    }
    if(bought)
    {
        cout << dollar << endl;
    }
    else
    {
        cout << "I need more Dollar!" << endl;
    }
    return 0;
}
