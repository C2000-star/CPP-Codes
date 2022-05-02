#include <iostream>
#include <queue>
#include <vector>
#define N 6
using namespace std;
void printFloodfill(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << grid[i][j] << " ";
        std::cout << std::endl;
    }
}
void floodfill(int i, int j, int grid[N][N], const int newNumber)
{
    queue<int> qx;
    queue<int> qy;
    int oldNumber = grid[i][j];
    if (oldNumber == newNumber)
        return;
    qx.push(i);
    qy.push(j);
    while (!qx.empty() && !qy.empty())
    {
        int x = qx.front();
        int y = qy.front();
        qx.pop();
        qy.pop();
        if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] != oldNumber)
            continue;
        else
        {
            grid[x][y] = newNumber;
            qx.push(x + 1);
            qy.push(y);
            qx.push(x - 1);
            qy.push(y);
            qx.push(x);
            qy.push(y + 1);
            qx.push(x);
            qy.push(y - 1);
        }
    }
    printFloodfill(grid);
}

int main()
{
    int grid[N][N] = {
        {0, 0, 0, 0, 2, 0},
        {0, 0, 2, 2, 0, 0},
        {0, 0, 2, 0, 0, 0},
        {0, 0, 2, 2, 0, 0},
        {0, 0, 2, 0, 0, 0},
        {0, 0, 2, 2, 0, 0}};

    int i = 2, j = 3;
    int newNumber = 1;
    floodfill(i, j, grid, newNumber);
    return 0;
}