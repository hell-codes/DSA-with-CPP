/*
QUESTION_8:
Fold a linked list.
The folding order is: First node, Last node,
                      Second node, Second-last node,
                      Third node, Third-last node
*/
#include <iostream>
#include <vector>
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
void print(node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    int n, x;
    cin >> n;

    node *head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        create(head, x);
    }
    vector<int> a;

    for (node *p = head; p; p = p->next)
        a.push_back(p->data);
    cout << "Link list data:";
    print(head);

    cout << "Link list data after fold:";
    int left = 0;
    int right = a.size() - 1;

    while (left <= right) {
        cout << a[left++] << " ";

        if (left <= right)
            cout << a[right--] << " ";
    }
    return 0;
}
