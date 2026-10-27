/*
Question_8:
Find the maximum XOR stamina by repeatedly jumping
to the next higher building on the right.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 0)
    {
        cout << 0;
        return 0;
    }
    vector<long long> height(n), dp(n, 0);

    for (int i = 0; i < n; i++)
        cin >> height[i];
    stack<int> st;
    long long answer = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && height[st.top()] <= height[i])
            st.pop();
        if (st.empty())
            dp[i] = height[i];
        else
        {
            int j = st.top();
            if (height[i] < height[j])
                dp[i] = height[i] ^ dp[j];
            else
                dp[i] = height[i];
        }
        if (dp[i] > answer)
            answer = dp[i];
        st.push(i);
    }
    cout << answer;
    return 0;
}
