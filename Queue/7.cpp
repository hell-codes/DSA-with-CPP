/*
Question_7:
Implement a Queue using Linked List.
Enqueue all elements and dequeue one element.
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *f = NULL;
node *r = NULL;

void enqueue(int d)
{
    node *n = new node;
    n->data = d;
    n->next = NULL;

    if(f == NULL)
        f = r = n;
    else
    {
        r->next = n;
        r = n;
    }
}
void dequeue()
{
    if(f == NULL)
        return;
    node *t = f;
    f = f->next;
    delete t;

    if(f == NULL)
        r = NULL;
}
void display()
{
    node *t = f;
    while(t != NULL)
    {
        cout << t->data << endl;
        t = t->next;
    }
}
int main()
{
    int n, x;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        enqueue(x);
    }
    display();
    dequeue();
    return 0;
}
