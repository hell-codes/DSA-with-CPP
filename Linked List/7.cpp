/*
QUESTION_7:
Given a linked list, delete all nodes that occur BEFORE
a specified node in the linked list.
If the given node is not present:
Print "Invalid Node!"
and display the original linked list.
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
    int n, x, p;
    cin >> n;

    node *head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        create(head, x);
    }
    cin >> p;
    node *t = head;

    while (t && t->data != p)
        t = t->next;
    if (!t) {
        cout << "Invalid Node! Linked List:";
        t = head;
        while (t) {
            cout << "->" << t->data;
            t = t->next;
        }
    }
    else {
        head = t;
        cout << "Linked List:";
        while (head) {
            cout << "->" << head->data;
            head = head->next;
        }
    }
    return 0;
}
