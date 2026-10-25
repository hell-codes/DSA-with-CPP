/*
Question_6:
Find the stock span for every day using a stack.
*/

#include <iostream>
#include <stack>
using namespace std;

void calculateSpan(int price[], int n, int S[])
{
    stack<int> st;

    S[0] = 1;
    st.push(0);

    for(int i = 1; i < n; i++)
    {
        while(!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        if(st.empty())
            S[i] = i + 1;
        else
            S[i] = i - st.top();
        st.push(i);
    }
}
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i];
        if(i < n - 1)
            cout << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int price[n];
    int S[n];

    for(int i = 0; i < n; i++)
        cin >> price[i];
    calculateSpan(price, n, S);
    printArray(S, n);
    return 0;
}
