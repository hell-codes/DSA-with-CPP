// There are n cities and m undirected streets. Find the minimum number
// of streets that must be closed so that there is no route from city 1 to n.
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 505

int capacity[MAXN][MAXN];
int adj[MAXN][MAXN];
int deg[MAXN];
int parent_node[MAXN];
int visited[MAXN];

int bfs(int n, int s, int t)
{
    memset(visited, 0, sizeof(visited));
    int queue[MAXN];
    int head = 0, tail = 0;

    queue[tail++] = s;
    visited[s] = 1;
    parent_node[s] = -1;
    while (head < tail)
    {
        int u = queue[head++];
        if (u == t)
            return 1;
        for (int i = 0; i < deg[u]; i++)
        {
            int v = adj[u][i];
            if (!visited[v] && capacity[u][v] > 0)
            {
                visited[v] = 1;
                parent_node[v] = u;
                queue[tail++] = v;
            }
        }
    }
    return 0;
}
void dfs_reach(int u)
{
    visited[u] = 1;
    for (int i = 0; i < deg[u]; i++)
    {
        int v = adj[u][i];
        if (!visited[v] && capacity[u][v] > 0)
            dfs_reach(v);
    }
}
void link(int u, int v)
{
    capacity[u][v] = 1;
    capacity[v][u] = 1;
    adj[u][deg[u]++] = v;
    adj[v][deg[v]++] = u;
}
int main()
{
    int n, m;
    if (cin >> n >> m)
    {
        int edges[1005][2];
        for (int i = 0; i < m; i++)
        {
            cin >> edges[i][0] >> edges[i][1];
            link(edges[i][0], edges[i][1]);
        }
        while (bfs(n, 1, n))
        {
            int curr = n;
            while (curr != 1)
            {
                int prev = parent_node[curr];
                capacity[prev][curr] -= 1;
                capacity[curr][prev] += 1;
                curr = prev;
            }
        }
        memset(visited, 0, sizeof(visited));
        dfs_reach(1);
        int cut_count = 0;
        int cut_edges[1005][2];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if ((visited[u] && !visited[v]) ||
                (visited[v] && !visited[u]))
            {
                cut_edges[cut_count][0] = u;
                cut_edges[cut_count][1] = v;
                cut_count++;
            }
        }
        cout << cut_count << "\n";
        for (int i = 0; i < cut_count; i++)
            cout << cut_edges[i][0] << " " << cut_edges[i][1] << "\n";
    }
    return 0;
}
