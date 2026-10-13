/*
Question_9:
Implement Circular Queue using Linked List and dequeue
two elements from the queue.
*/

#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
node *f = NULL, *r = NULL;

void enqueue(int d) {
    node *n = new node;
    n->data = d;
    n->next = NULL;
    if(f == NULL)
        f = r = n, n->next = f;
    else {
        n->next = f;
        r->next = n;
        r = n;
    }
}
void dequeue() {
    if(f == NULL) return;

    node *t = f;
    if(f == r)
        f = r = NULL;
    else {
        f = f->next;
        r->next = f;
    }
    delete t;
}
void print() {
    if(f == NULL) return;
    node *t = f;
    do {
        cout << t->data << " ";
        t = t->next;
    } while(t != f);
    cout << endl;
}
int main() {
    int n, x;
    cin >> n;
    while(n--) {
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
