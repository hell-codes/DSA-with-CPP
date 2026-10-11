/*
Question_3:
Create a queue, enqueue all elements, then dequeue
one by one and display the remaining queue.
*/

#include <iostream>
using namespace std;

class Queue
{
    int a[100], front, rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }
    void enqueue(int data)
    {
        a[++rear] = data;
    }
    void dequeue()
    {
        if(front > rear)
            return;
        front++;

        for(int i = front; i <= rear; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};
int main()
{
    int n, x;
    cin >> n;

    Queue q;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        q.enqueue(x);
    }
    cout << "Dequeuing elements:" << endl;

    for(int i = 0; i < n; i++)
        q.dequeue();
    return 0;
}
