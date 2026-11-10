// n cities start disconnected. Add one road each day and print the number
// of connected components and the size of the largest connected component.
#include <iostream>
using namespace std;

#define MAXN 100005

int parent_node[MAXN];
int sz[MAXN];
int num_components;
int max_size;
void initDSU(int n)
{
    num_components = n;
    max_size = 1;

    for (int i = 1; i <= n; i++)
    {
        parent_node[i] = i;
        sz[i] = 1;
    }
}
int find(int i)
{
    if (parent_node[i] == i)
        return i;
    return parent_node[i] = find(parent_node[i]);
}
int join(int i, int j)
{
    int root_i = find(i);
    int root_j = find(j);

    if (root_i != root_j)
    {
        if (sz[root_i] < sz[root_j])
        {
            int temp = root_i;
            root_i = root_j;
            root_j = temp;
        }
        parent_node[root_j] = root_i;
        sz[root_i] += sz[root_j];
        if (sz[root_i] > max_size)
            max_size = sz[root_i];

        num_components--;
        return 1;
    }
    return 0;
}
int main()
{
    int n, m;
    if (cin >> n >> m)
    {
        initDSU(n);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            join(u, v);
            cout << num_components << " " << max_size << "\n";
        }
    }
    return 0;
}
