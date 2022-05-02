#include <iostream>
#include <math.h>
#include <vector>
#define N 10
#define E 13
using namespace std;

void printDistance(vector<double> &dist)
{
    for (int i = 0; i < N; i++)
        std::cout << dist[i] << " ";
}
void bellmanFord(int edges[E][3], int s)
{
    vector<double> dist(N, INFINITY);
    dist[s] = 0;
    for (int i = 0; i < N - 1; i++)
        for (int i = 0; i < E; i++)
            if (dist[edges[i][0]] + edges[i][2] < dist[edges[i][1]])
                dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];

    for (int i = 0; i < N - 1; i++)
        for (int i = 0; i < E; i++)
            if (dist[edges[i][0]] + edges[i][2] < dist[edges[i][1]])
                dist[edges[i][1]] = -INFINITY;

    printDistance(dist);
}
int main()
{
    int edges[E][3] = {
        {0, 1, 5},
        {1, 2, 20},
        {1, 6, 60},
        {1, 5, 30},
        {2, 3, 10},
        {2, 4, 75},
        {3, 2, -15},
        {4, 9, 100},
        {5, 4, 25},
        {5, 8, 50},
        {5, 6, 5},
        {6, 7, -50},
        {7, 8, -10},
    };
    bellmanFord(edges, 0);
    return 0;
}