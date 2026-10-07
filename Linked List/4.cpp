/*
QUESTION_4:
Given a linked list, insert a new node before a given node P.
*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
void display(node *start) {
    cout << "Linked List:";
    while (start) {
        cout << "->" << start->data;
        start = start->next;
    }
}
int main() {
    int n, x, p;
    cin >> n;

    node *head = NULL;
    node *tail = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        node *t = new node{x, NULL};
        if (!head)
            head = tail = t;
        else {
            tail->next = t;
            tail = t;
        }
    }
    cin >> p;
    cin >> x;

    node *newNode = new node{x, NULL};

    if (head && head->data == p) {
        newNode->next = head;
        head = newNode;
        display(head);
        return 0;
    }
    node *t = head;

    while (t && t->next && t->next->data != p)
        t = t->next;
    if (!t || !t->next) {
        cout << "Node not found!";
        display(head);
    }
    else {
        newNode->next = t->next;
        t->next = newNode;
        display(head);
    }
    return 0;
}
