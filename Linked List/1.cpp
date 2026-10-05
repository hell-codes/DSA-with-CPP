/*
QUESTION_1:
Given a linked list and a data value D, delete all the nodes
containing D from the linked list and display the final linked list.
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
void del(node *&head, int x) {
    while (head && head->data == x)
        head = head->next;
    node *p = head;

    while (p && p->next) {
        if (p->next->data == x)
            p->next = p->next->next;
        else
            p = p->next;
    }
}
int main() {
    int n, x;
    cin >> n;

    node *head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        create(head, x);
    }
    cin >> x;
    del(head, x);

    cout << "Linked List:";
    while (head) {
        cout << "->" << head->data;
        head = head->next;
    }
    return 0;
}
