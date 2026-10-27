/*
Question_10:
Convert a postfix expression into a prefix expression using a stack.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;
string postToPre(string post_exp)
{
    stack<string> s;
    for(int i = 0; i < post_exp.length(); i++)
    {
        char ch = post_exp[i];
        if(isalnum(ch))
        {
            s.push(string(1, ch));
        }
        else
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string result = string(1, ch) + op1 + op2;
            s.push(result);
        }
    }
    return s.top();
}
int main()
{
    string post_exp;
    cin >> post_exp;
    cout << postToPre(post_exp);
    return 0;
}
