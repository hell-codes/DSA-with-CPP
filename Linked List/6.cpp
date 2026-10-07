/*
QUESTION_6:
Create a linked list and find the data stored at a given index.
The function required is:
int GetNth(struct node* head, int index)
The linked list should be displayed first,
followed by the node present at the given index.
*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
int GetNth(node *head, int index) {
    for (int i = 0; i < index; i++)
        head = head->next;

    return head->data;
}
int main() {
    int n, x, index;
    cin >> n;

    node *head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;

        node *p = new node{x, head};
        head = p;
    }
    cin >> index;
    cout << "Linked list:-->";
    node *p = head;

    while (p) {
        cout << p->data;
        if (p->next)
            cout << "-->";
        p = p->next;
    }
    cout << endl;

    cout << "Node at index=" << index << ":"
         << GetNth(head, index);
    return 0;
}
