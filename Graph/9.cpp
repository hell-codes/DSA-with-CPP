// There are n rooms and m directed teleports. Each teleporter can be used at
// most once. Find the maximum number of days Teddy can travel from room 1 to n.
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
int main()
{
    int n, m;
    if (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            capacity[u][v] = 1;
            adj[u][deg[u]++] = v;
            adj[v][deg[v]++] = u;
        }
        int max_days = 0;
        while (bfs(n, 1, n))
        {
            max_days++;
            int curr = n;
            while (curr != 1)
            {
                int prev = parent_node[curr];

                capacity[prev][curr] -= 1;
                capacity[curr][prev] += 1;
                curr = prev;
            }
        }
        cout << max_days << "\n";
        for (int d = 0; d < max_days; d++)
        {
            int path[MAXN];
            int len = 0;
            int curr = 1;
            path[len++] = curr;
            while (curr != n)
            {
                for (int i = 0; i < deg[curr]; i++)
                {
                    int v = adj[curr][i];
                    if (capacity[v][curr] > 0)
                    {
                        capacity[v][curr] = 0;
                        curr = v;
                        path[len++] = curr;
                        break;
                    }
                }
            }
            cout << len << "\n";
            for (int i = 0; i < len; i++)
            {
                cout << path[i];
                if (i != len - 1)
                    cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
