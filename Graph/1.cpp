// Teddy has n cities and m bidirectional roads, each requiring some tokens.
// Choose minimum-cost tokens so every city can reach every other city.
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100005
struct Edge {
    int u, v, mask;
};
vector<int> parent(MAXN);
long long cost[60];
Edge edges[MAXN];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
        cin >> cost[i];

    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;

        int mask = 0;
        for (int j = 0; j < l; j++) {
            int token;
            cin >> token;
            token--;
            mask |= (1 << token);
        }
        edges[i] = {u, v, mask};
    }
    long long minCost = -1;

    for (int mask = 0; mask < (1 << k); mask++) {

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        int components = n;
        for (int i = 0; i < m; i++) {
            if ((edges[i].mask & mask) == edges[i].mask) {

                int ru = find(edges[i].u);
                int rv = find(edges[i].v);

                if (ru != rv) {
                    parent[ru] = rv;
                    components--;
                }
            }
        }
        if (components == 1) {
            long long currentCost = 0;

            for (int i = 0; i < k; i++)
                if ((mask >> i) & 1)
                    currentCost += cost[i];

            if (minCost == -1 || currentCost < minCost)
                minCost = currentCost;
        }
    }
    cout << minCost << endl;
    return 0;
}
