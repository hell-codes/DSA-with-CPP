/*
Question_9:
Implement a stack using a single queue.
Push elements so the newest element stays at the front.
*/

#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q;

public:
    void push(int val)
    {
        int n = q.size();
        q.push(val);
        for(int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if(!q.empty())
            q.pop();
    }
    int top()
    {
        return q.front();
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Stack s;
    int x;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }
    cout << "top of element " << s.top() << endl;

    for(int i = 0; i < m; i++)
        s.pop();
    cout << "top of element " << s.top();
    return 0;
}
