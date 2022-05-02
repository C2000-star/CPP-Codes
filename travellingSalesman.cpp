#include <iostream>
#define N 5
using namespace std;
int dist[N][N] = {
    {0, 5, 2, INT_MAX, 8},
    {2, 0, 7, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, 0, 2, 9},
    {INT_MAX, 1, INT_MAX, 0, INT_MAX},
    {INT_MAX, INT_MAX, 1, 1, 0},
};
int dp[16][N];
int VISITED_ALL = (1 << N) - 1;
int tsp(int mask, int pos)
{
    int ans = INT_MAX;
    if (mask == VISITED_ALL)
        return dist[pos][0];
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    for (int i = 0; i < N; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newAns;
            if (dist[pos][i] == INT_MAX || tsp(mask | 1 << i, i) == INT_MAX)
                newAns = INT_MAX;
            else
                newAns = dist[pos][i] + tsp(mask | 1 << i, i);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}
int main()
{
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;
    std::cout << "Hamiltonian path with minimum cost: " << tsp(1, 0);
    return 0;
}