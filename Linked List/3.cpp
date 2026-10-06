/*
QUESTION_3:
Insert the given elements into a Circular Linked List in sorted order.
The final Circular Linked List must contain the elements
in ascending order.
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
void sortedInsert(Node *&head, int x) {
    Node *p = new Node{x, NULL};

    if (!head) {
        head = p;
        p->next = head;
        return;
    }
    if (x <= head->data) {
        Node *t = head;

        while (t->next != head)
            t = t->next;
        p->next = head;
        t->next = p;
        head = p;
        return;
    }
    Node *t = head;

    while (t->next != head && t->next->data < x)
        t = t->next;
    p->next = t->next;
    t->next = p;
}
int main() {
    int n, x;
    cin >> n;

    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sortedInsert(head, x);
    }
    Node *p = head;

    for (int i = 0; i < n; i++) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}
