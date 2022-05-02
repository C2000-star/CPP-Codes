#include <iostream>
#include <vector>
#define N 11
std::vector<int> graphEdges[N];

bool isCycleUtil(std::vector<bool> visited, int x)
{
    if (visited[x])
        return true;
    visited[x] = true;
    for (int i = 0; i < graphEdges[x].size(); i++)
    {
        if (isCycleUtil(visited, graphEdges[x][i]))
            return true;
    }
    return false;
}
bool isCycle()
{
    std::vector<bool> visited(N, false);
    for (int i = 0; i < N; i++)
    {
        visited[i] = true;
        for (int j = 0; j < graphEdges[i].size(); j++)
        {
            if (isCycleUtil(visited, graphEdges[i][j]))
                return true;
        }
        visited[i] = false;
    }
    return false;
}
int dfs(int x, int k, std::vector<int> &ans, std::vector<bool> &visited)
{
    visited[x] = true;
    for (int i = 0; i < graphEdges[x].size(); i++)
    {
        if (!visited[graphEdges[x][i]])
            k = dfs(graphEdges[x][i], k, ans, visited);
    }
    ans[k] = x;
    return k - 1;
}
void topologicalSort()
{
    std::vector<bool> visited(N, false);
    std::vector<int> ans(N);
    int k = N - 1;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            k = dfs(i, k, ans, visited);
    }
    for (int i = 0; i < N; i++)
        std::cout << ans[i] << " ";
}
void addEdge(int x, int y)
{
    graphEdges[x].push_back(y);
}
int main()
{
    addEdge(0, 1);
    addEdge(1, 4);
    addEdge(4, 7);
    addEdge(7, 9);
    addEdge(0, 2);
    addEdge(2, 5);
    addEdge(5, 7);
    addEdge(0, 3);
    addEdge(3, 6);
    addEdge(6, 8);
    addEdge(8, 9);
    addEdge(8, 10);

    if (isCycle())
        std::cout << "Cycle detected! No topological sort is possible";
    else
        topologicalSort();
    return 0;
}