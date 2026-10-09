/*
QUESTION_10:
Given a linked list, delete D nodes from the beginning
of the linked list.
*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
void create(node *&head, int x) {
    node *p = new node{x, NULL};

    if (!head)
        head = p;
    else {
        node *t = head;
        while (t->next)
            t = t->next;

        t->next = p;
    }
}
int main() {
    int n, x, d;
    cin >> n;

    node *head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        create(head, x);
    }
    cin >> d;
    while (head && d--)
        head = head->next;

    cout << "Linked List:";

    while (head) {
        cout << "->" << head->data;
        head = head->next;
    }
    return 0;
}
