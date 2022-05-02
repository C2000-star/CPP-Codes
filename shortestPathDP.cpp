#include <iostream>
#include <string.h>
#define N 6

using namespace std;

int shortestPathDp(int num, int graph[][N])
{
    int dp[num];
    for (int i = 0; i < num; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[num - 1] = 0;
    for (int i = num - 2; i >= 0; i--)
    {
        for (int j = 0; j < num; j++)
        {
            int weight = graph[i][j];
            if (weight > 0)
            {
                dp[i] = min(dp[i], weight + dp[j]);
            }
        }
    }
    return dp[0];
}
int main()
{
    int graph[N][N];
    memset(graph, 0, sizeof graph);
    graph[0][1] = 3;
    graph[0][2] = 2;
    graph[1][2] = 4;
    graph[1][3] = 11;
    graph[1][4] = 4;
    graph[2][3] = 6;
    graph[2][4] = 5;
    graph[3][4] = 3;
    graph[3][5] = 7;
    graph[4][5] = 4;
    std::cout << "Shortest path weight: " << shortestPathDp(N, graph);
    return 0;
}