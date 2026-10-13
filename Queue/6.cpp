/*
Question_6:
Implement a Circular Queue using an array.
Insert elements, display the queue,
delete two elements and display again.
*/

#include <iostream>
using namespace std;

struct Queue
{
    int a[100];
    int front = -1, rear = -1;
};
void enQueue(Queue* q, int value)
{
    if((q->rear + 1) % 100 == q->front)
        return;
    if(q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % 100;
    q->a[q->rear] = value;
}
int deQueue(Queue* q)
{
    if(q->front == -1)
        return -1;
    int x = q->a[q->front];

    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % 100;
    return x;
}
void displayQueue(Queue* q)
{
    if(q->front == -1)
        return;
    int i = q->front;
    while(true)
    {
        cout << q->a[i] << " ";
        if(i == q->rear)
            break;
        i = (i + 1) % 100;
    }
}
int main()
{
    Queue q;
    int n, x;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        enQueue(&q, x);
    }
    cout << "Elements in Circular Queue are:";
    displayQueue(&q);
    cout << endl;
    cout << "Deleted value = " << deQueue(&q) << endl;
    cout << "Deleted value = " << deQueue(&q);
    cout << "\nElements in Circular Queue are:";
    displayQueue(&q);
    cout << endl;
    return 0;
}
