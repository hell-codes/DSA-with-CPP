/*
QUESTION_9:
Create a Circular Linked List containing numbers from 1 to N.
Then split the Circular Linked List into:
1. Odd Circular Linked List
2. Even Circular Linked List
*/
#include <iostream>
using namespace std;

struct n {
    int data;
    n *next;
};
void insert(int data, n *&head) {
    n *p = new n{data, NULL};

    if (!head) {
        head = p;
        p->next = head;
    }
    else {
        n *t = head;

        while (t->next != head)
            t = t->next;

        t->next = p;
        p->next = head;
    }
}
void display(n *h) {
    if (!h)
        return;
    n *p = h;

    do {
        cout << p->data << "=>";
        p = p->next;
    } while (p != h);
    cout << "[h]";
}
int main() {
    int N;
    cin >> N;

    n *all = NULL;
    n *odd = NULL;
    n *even = NULL;

    for (int i = 1; i <= N; i++) {
        insert(i, all);
        if (i % 2)
            insert(i, odd);
        else
            insert(i, even);
    }
    cout << "Complete linked_list:\n[h]=>";
    display(all);
    cout << "\nOdd:\n[h]=>";
    display(odd);
    cout << "\nEven:\n[h]=>";
    display(even);
    return 0;
}
