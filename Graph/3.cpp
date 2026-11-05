// There are n rooms and m directed teleports. Each teleporter can be used only
// once. Find the maximum number of days Teddy can travel from room 1 to room n
// and print the routes used for each day.
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 505
int capacity[MAXN][MAXN];
int adj[MAXN][MAXN];
int degreeCount[MAXN];
int parentNode[MAXN];
int visited[MAXN];

int bfs(int n, int s, int t)
{
    memset(visited, 0, sizeof(visited));
    int queue[MAXN], head = 0, tail = 0;
    queue[tail++] = s;
    visited[s] = 1;
    parentNode[s] = -1;

    while (head < tail)
    {
        int u = queue[head++];
        if (u == t)
            return 1;
        for (int i = 0; i < degreeCount[u]; i++)
        {
            int v = adj[u][i];
            if (!visited[v] && capacity[u][v] > 0)
            {
                visited[v] = 1;
                parentNode[v] = u;
                queue[tail++] = v;
            }
        }
    }
    return 0;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        capacity[u][v] = 1;
        adj[u][degreeCount[u]++] = v;
        adj[v][degreeCount[v]++] = u;
    }
    int maxDays = 0;
    while (bfs(n, 1, n))
    {
        maxDays++;
        int current = n;
        while (current != 1)
        {
            int previous = parentNode[current];
            capacity[previous][current]--;
            capacity[current][previous]++;
            current = previous;
        }
    }
    cout << maxDays << endl;
    for (int d = 0; d < maxDays; d++)
    {
        int path[MAXN], length = 0;
        int current = 1;
        path[length++] = current;
        while (current != n)
        {
            for (int i = 0; i < degreeCount[current]; i++)
            {
                int v = adj[current][i];
                if (capacity[v][current] > 0)
                {
                    capacity[v][current] = 0;
                    current = v;
                    path[length++] = current;
                    break;
                }
            }
        }
        cout << length << endl;
        for (int i = 0; i < length; i++)
        {
            if (i) cout << " ";
            cout << path[i];
        }
        cout << endl;
    }
    return 0;
}
