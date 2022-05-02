#include <iostream>
#include <vector>
#include <set>
#define N 5

int minVertex(std::vector<int> &nodes, std::vector<bool> &s)
{
    int index = 0;
    int minValue = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        if (!s[i] && nodes[i] < minValue)
        {
            minValue = nodes[i];
            index = i;
        }
    }
    return index;
}
void mst(int edges[][N])
{
    std::vector<int> nodes(N, INT_MAX);
    std::vector<bool> s(N, false);
    nodes[0] = 0;
    std::vector<int> ans(N);
    ans[0] = -1;
    for (int i = 0; i < N - 1; i++)
    {
        int e = minVertex(nodes, s);
        s[e] = true;
        for (int j = 0; j < N; j++)
        {
            if (edges[e][j] && !s[j] && edges[e][j] < nodes[j])
            {
                nodes[j] = edges[e][j];
                ans[j] = e;
            }
        }
    }

    for (int i = 1; i < ans.size(); i++)
        std::cout << ans[i] << "->" << i << "\n";
    int total = 0;
    for (int i = 0; i < nodes.size(); i++)
        total += nodes[i];
    std::cout << "The total weight of the minimum spanning tree is: " << total << std::endl;
}
int main()
{
    int edges[N][N] = {
        {0, 20, 30, 0, 0},
        {20, 0, 0, 40, 0},
        {30, 0, 0, 7, 10},
        {0, 40, 7, 0, 11},
        {0, 0, 10, 11, 0},
    };

    mst(edges);
    return 0;
}