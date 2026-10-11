/*
Question_2:
Given a binary string, flip the bit at each given position.
After every flip, print the length of the longest substring
whose bits are all the same.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
    int len;
    int left, right;
    int pref, suff, best;
};
Node tree[800005];
string s;

void pull(int k, int l, int r)
{
    if(l == r)
    {
        tree[k] = {1, s[l] - '0', s[l] - '0', 1, 1, 1};
        return;
    }
    int mid = (l + r) / 2;
    Node a = tree[k * 2];
    Node b = tree[k * 2 + 1];

    tree[k].len = a.len + b.len;
    tree[k].left = a.left;
    tree[k].right = b.right;

    tree[k].pref = a.pref;
    if(a.pref == a.len && a.right == b.left)
        tree[k].pref = a.len + b.pref;

    tree[k].suff = b.suff;
    if(b.suff == b.len && a.right == b.left)
        tree[k].suff = b.len + a.suff;

    tree[k].best = max(a.best, b.best);

    if(a.right == b.left)
        tree[k].best = max(tree[k].best, a.suff + b.pref);
}
void build(int k, int l, int r)
{
    if(l == r)
    {
        tree[k] = {1, s[l] - '0', s[l] - '0', 1, 1, 1};
        return;
    }
    int mid = (l + r) / 2;

    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);

    pull(k, l, r);
}
void update(int k, int l, int r, int pos)
{
    if(l == r)
    {
        s[l] = (s[l] == '0') ? '1' : '0';
        tree[k] = {1, s[l] - '0', s[l] - '0', 1, 1, 1};
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid)
        update(k * 2, l, mid, pos);
    else
        update(k * 2 + 1, mid + 1, r, pos);
    pull(k, l, r);
}
int main()
{
    cin >> s;
    int n = s.length();

    int m;
    cin >> m;

    build(1, 0, n - 1);
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        update(1, 0, n - 1, x - 1);
        cout << tree[1].best;
        if(i < m - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}
