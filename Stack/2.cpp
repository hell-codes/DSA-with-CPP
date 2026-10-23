/*
Question_2:
Implement two stacks, push elements into both stacks, pop elements
to reverse them, and merge the second stack after the first stack.
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
struct mystack
{
    node *top;
};
void push(int data, mystack* ms)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = ms->top;
    ms->top = newnode;
}
int pop(mystack* ms)
{
    if(ms->top == NULL)
        return -1;
    node *temp = ms->top;
    int data = temp->data;
    ms->top = ms->top->next;
    delete temp;
    return data;
}
void merge(mystack* ms1, mystack* ms2)
{
    if(ms1->top == NULL)
    {
        ms1->top = ms2->top;
        return;
    }
    node *temp = ms1->top;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ms2->top;
}
int main()
{
    int n, m;
    cin >> n >> m;

    mystack ms1;
    mystack ms2;

    ms1.top = NULL;
    ms2.top = NULL;

    int value;

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        push(value, &ms1);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> value;
        push(value, &ms2);
    }
    merge(&ms1, &ms2);
    node *temp = ms1.top;
    while(temp != NULL)
    {
        cout << temp->data;
        if(temp->next != NULL)
            cout << " ";
        temp = temp->next;
    }
    return 0;
}
