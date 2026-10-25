/*
Question_4:
Implement two stacks using one array.
Push alternate elements into stack1 and stack2,
then pop one element from each stack.
*/

#include <iostream>
using namespace std;

class twoStacks
{
    int arr[5];
    int top1, top2;

public:
    twoStacks()
    {
        top1 = -1;
        top2 = 5;
    }
    void push1(int x)
    {
        if(top1 + 1 < top2)
            arr[++top1] = x;
    }
    void push2(int x)
    {
        if(top1 + 1 < top2)
            arr[--top2] = x;
    }
    int pop1()
    {
        if(top1 == -1)
            return -1;
        return arr[top1--];
    }
    int pop2()
    {
        if(top2 == 5)
            return -1;
        return arr[top2++];
    }
};
int main()
{
    twoStacks ts;
    int x;
    for(int i = 1; i <= 5; i++)
    {
        cin >> x;
        if(i % 2 == 1)
            ts.push1(x);
        else
            ts.push2(x);
    }
    cout << "Popped element from stack1 is:" << ts.pop1() << endl;
    cout << "Popped element from stack2 is:" << ts.pop2() << endl;
    return 0;
}
