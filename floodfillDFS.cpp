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
    if (i < 0 || i >= N || j < 0 || j >= N || grid[i][j] != 0)
        return;
    grid[i][j] = newNumber;
    floodfill(i + 1, j, grid, newNumber);
    floodfill(i - 1, j, grid, newNumber);
    floodfill(i, j + 1, grid, newNumber);
    floodfill(i + 1, j - 1, grid, newNumber);
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
    int oldNumber = grid[i][j];
    if (newNumber != oldNumber)
        floodfill(i, j, grid, newNumber);
    printFloodfill(grid);
    return 0;
}