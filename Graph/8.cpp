// Given a tree with n nodes, find the maximum number of edges
// that can be selected so that no two selected edges share a node.
#include <iostream>
using namespace std;

#define MAXN 200005

struct Edge
{
    int to;
    Edge* next;
};
Edge* head[MAXN];
int dp[MAXN][2];

void addEdge(int u, int v)
{
    Edge* e1 = new Edge;
    e1->to = v;
    e1->next = head[u];
    head[u] = e1;
    Edge* e2 = new Edge;
    e2->to = u;
    e2->next = head[v];
    head[v] = e2;
}
void link(int i, int j)
{
    addEdge(i, j);
}
void dfs(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = 0;

    int sum_max = 0;
    for (Edge* e = head[u]; e != NULL; e = e->next)
    {
        int v = e->to;
        if (v != p)
        {
            dfs(v, u);
            int best_child = (dp[v][0] > dp[v][1]) ? dp[v][0] : dp[v][1];
            sum_max += best_child;
        }
    }
    dp[u][0] = sum_max;
    for (Edge* e = head[u]; e != NULL; e = e->next)
    {
        int v = e->to;
        if (v != p)
        {
            int best_child = (dp[v][0] > dp[v][1]) ? dp[v][0] : dp[v][1];
            int take_edge = 1 + dp[v][0] + (sum_max - best_child);

            if (take_edge > dp[u][1])
                dp[u][1] = take_edge;
        }
    }
}
int main()
{
    int n;
    if (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            head[i] = NULL;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            link(u, v);
        }
        dfs(1, 0);
        int ans = (dp[1][0] > dp[1][1]) ? dp[1][0] : dp[1][1];
        cout << ans << "\n";
    }
    return 0;
}
