#include <iostream>
#include <vector>
#include <queue>
#define N 1000
using namespace std;

vector<int> adj[N];
queue<int> q;
bool visited[N];
void bfs(int node)
{
    for (auto e : adj[node])
    {
        // std::cout << e << " ";
        if (!visited[e])
        {
            visited[e] = true;
            q.push(e);
        }
    }

    std::cout << q.front() << " ";
    q.pop();
    if (!q.empty())
        bfs(q.front());
}

int main()
{
    int n, m, x, y;
    std::cin >> n >> m;
    for (int i = 0; i <= n; i++)
        visited[i] = false;

    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    q.push(1);
    visited[1] = true;
    bfs(1);
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using std::cin;
// using std::cout;
// using std::queue;
// using std::vector;
// vector<vector<int>> v;
// vector<bool> visited;
// void bfs(int node)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;
//     while (!q.empty())
//     {
//         node = q.front();
//         q.pop();
//         cout << node << " ";
//         for (int i = 0; i < v[node].size(); i++)
//         {
//             if (!visited[v[node][i]])
//             {
//                 q.push(v[node][i]);
//                 visited[v[node][i]] = true;
//             }
//         }
//     }
// }
// int main()
// {
//     char ch;
//     int x, y;
//     v.resize(7);
//     visited.resize(6);
//     while (1)
//     {
//         cout << "\nWant to insert an edge?";
//         cin >> ch;
//         if (ch == 'y' || ch == 'Y')
//         {
//             cout << "Enter the end points of the edge:";
//             cin >> x >> y;
//             v[x].push_back(y);
//             v[y].push_back(x);
//         }
//         else
//         {
//             break;
//         }
//     }
//     bfs(1);
//     return 0;
// }