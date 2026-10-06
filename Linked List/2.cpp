/*
QUESTION_2:
Insert a new node at the beginning of a Doubly Linked List.
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void insertStart(Node *&head, int x) {
    Node *p = new Node{x, head, NULL};
    if (head)
        head->prev = p;
    head = p;
}
int main() {
    int n, x;
    cin >> n;

    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertStart(head, x);
    }
    Node *p = head;

    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    p = head;

    while (p->next)
        p = p->next;
    while (p) {
        cout << p->data << " ";
        p = p->prev;
    }
    return 0;
}
