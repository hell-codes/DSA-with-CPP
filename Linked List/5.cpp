/*
QUESTION_5:
Delete alternate nodes from a singly linked list.
The deletion starts from the SECOND node.
*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
void insert_Data(node *&head, int x) {
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
void delete_Alt(node *head) {
    while (head && head->next) {
        head->next = head->next->next;
        head = head->next;
    }
}
int main() {
    int n;
    cin >> n;

    node *head = NULL;

    for (int i = 1; i <= n; i++)
        insert_Data(head, i);

    delete_Alt(head);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
