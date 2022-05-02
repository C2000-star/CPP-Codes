#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int dist(int s, int t, int n, vector<int> adjEdges[])
{
    queue<int> q;
    vector<bool> visited(n + 1, 0);
    vector<int> distance(n + 1, INT_MAX);
    distance[s] = 0;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int sizeAdj = adjEdges[x].size();
        for (int i = 0; i < sizeAdj; i++)
        {
            if (visited[adjEdges[x][i]])
                continue;
            q.push(adjEdges[x][i]);
            distance[adjEdges[x][i]] = distance[x] + 1;
            visited[adjEdges[x][i]] = true;
        }
    }
    return distance[t];
}
void solve(int n, int k, vector<int> edges[], vector<int> A)
{
    int d, temp = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d = 0;
            else
                d = dist(i, j, n, edges);
            temp += pow(k, d) * A[j];
        }
        std::cout << temp << " ";
        temp = 0;
    }
}
int main()
{
    int n, k;
    std::vector<int> A;
    std::cin >> n >> k;
    std::vector<int> edges[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        A.push_back(a);
    }
    solve(n, k, edges, A);
    return 0;
}