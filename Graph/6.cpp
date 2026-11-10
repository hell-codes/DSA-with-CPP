// There are n boys, m girls and k possible pairs. Find the maximum number of
// valid boy-girl pairs where each person can belong to at most one pair.
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 1005

int pairBoy[MAXN], pairGirl[MAXN];
int graph[MAXN][MAXN], degreeCount[MAXN], visited[MAXN];
void link(int u, int v)
{
    graph[u][degreeCount[u]++] = v;
}
int dfs(int u)
{
    for (int i = 0; i < degreeCount[u]; i++)
    {
        int v = graph[u][i];
        if (!visited[v])
        {
            visited[v] = 1;
            if (pairGirl[v] == -1 || dfs(pairGirl[v]))
            {
                pairGirl[v] = u;
                pairBoy[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < MAXN; i++)
        pairBoy[i] = pairGirl[i] = -1;

    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        link(u, v);
    }
    int maxPairs = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));

        if (dfs(i))
            maxPairs++;
    }
    cout << maxPairs << endl;
    for (int i = 1; i <= n; i++)
        if (pairBoy[i] != -1)
            cout << i << " " << pairBoy[i] << endl;
    return 0;
}
