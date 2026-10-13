/*
Question_10:
Reverse a Queue.
The queue follows FIFO architecture.
Enqueue all elements, display the queue,
then reverse and display the reversed queue.
*/

#include <iostream>
using namespace std;

int q[100];
int front = -1;
int rear = -1;

void enqueue(int data, int l)
{
    if(front == -1)
        front = 0;
    rear++;
    q[rear] = data;
}
void reverse()
{
    int i = front;
    int j = rear;
    while(i < j)
    {
        swap(q[i], q[j]);
        i++;
        j--;
    }
}
int main()
{
    int n, t;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> t;
        enqueue(t, n);
    }
    cout << "Queue:";

    for(int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
    reverse();
    cout << "Reversed Queue:";
    for(int i = front; i <= rear; i++)
        cout << q[i] << " ";
    return 0;
}
