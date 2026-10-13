/*
Question_5:
Implement a Queue using an Array.
Enqueue each element and display the queue after every insertion.
*/

#include <iostream>
using namespace std;

int q[100];
int front = -1, rear = -1;

void enqueue(int data)
{
    if(rear == 99)
        return;
    if(front == -1)
        front = 0;

    rear++;
    q[rear] = data;
}
void display()
{
    for(int i=front;i<=rear;i++)
        cout << q[i] << " ";
    cout << " ";
}
int main()
{
    int n, data;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> data;
        cout << "Enqueuing " << data << endl;
        enqueue(data);
        display();
        cout << endl;
    }
    return 0;
}
