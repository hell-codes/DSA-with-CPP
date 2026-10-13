/*
Question_4:
Implement a Queue using Linked List.
Enqueue elements, dequeue elements and print the queue.
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *front = NULL;
node *rear = NULL;

void enqueue(int d)
{
    node *new_n = new node;
    new_n->data = d;
    new_n->next = NULL;

    if(front == NULL)
        front = rear = new_n;
    else
    {
        rear->next = new_n;
        rear = new_n;
    }
}
void dequeue()
{
    if(front == NULL)
        return;
    node *temp = front;
    front = front->next;
    if(front == NULL)
        rear = NULL;

    delete temp;
}
void print()
{
    node *p = front;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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
    print();
    dequeue();
    print();
    dequeue();
    print();
    return 0;
}
