// Byteland has n cities and m roads. Add the minimum number of roads so that
// every city becomes connected, and print the new roads that must be added.
#include <iostream>
using namespace std;

#define MAXN 100005

int parent[MAXN];
int find(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}
void unite(int i, int j)
{
    int rootI = find(i);
    int rootJ = find(j);
    if (rootI != rootJ)
        parent[rootI] = rootJ;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }
    int components[MAXN], count = 0;

    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            components[count++] = i;

    cout << count - 1 << endl;

    for (int i = 0; i < count - 1; i++)
        cout << components[i] << " " << components[i + 1] << endl;

    return 0;
}
