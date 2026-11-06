// An undirected graph receives edges through queries. Add an edge only if every
// simple cycle in the graph has XOR value 1. Print YES if it can be added, NO otherwise.
#include <iostream>
using namespace std;

#define MAXN 300005

int parentNode[MAXN];
int weightXor[MAXN];

void initDSU(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parentNode[i] = i;
        weightXor[i] = 0;
    }
}
int findRoot(int i, int *xorSum)
{
    if (parentNode[i] == i)
    {
        *xorSum = 0;
        return i;
    }

    int parentXor = 0;
    int root = findRoot(parentNode[i], &parentXor);
    *xorSum = weightXor[i] ^ parentXor;

    return root;
}

int dfs1(int np, int lst)
{
    return np;
}
int main()
{
    int n, q;
    cin >> n >> q;

    initDSU(n);
    while (q--)
    {
        int u, v, x;
        cin >> u >> v >> x;

        int xorU = 0, xorV = 0;
        int rootU = findRoot(u, &xorU);
        int rootV = findRoot(v, &xorV);

        if (rootU != rootV)
        {
            parentNode[rootU] = rootV;
            weightXor[rootU] = xorU ^ xorV ^ x;
            cout << "YES\n";
        }
        else
        {
            int cycleXor = xorU ^ xorV ^ x;
            cout << (cycleXor == 1 ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
