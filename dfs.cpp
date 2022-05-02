#include <iostream>
#include <vector>
#define N 6
using namespace std;
bool visited[N];
vector<int> adj[N];
void dfs(int node)
{
    visited[node] = true;
    for (auto e : adj[node])
    {
        if (!visited[e])
            dfs(e);
    }
    cout << node << " ";
}
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    return 0;
}