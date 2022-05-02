#include <iostream>
using namespace std;
#define N 9
#define UNASSIGNED 0

bool locationUnassigned(int grid[N][N], int &row, int &col);

bool isPossible(int grid[N][N], int row, int col, int num);

bool solveSudoku(int grid[N][N])
{
    int row, col;

    if (!locationUnassigned(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isPossible(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

bool locationUnassigned(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool rowCheck(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}

bool columnCheck(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
    {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}

bool boxCheck(int grid[N][N], int r, int c, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + r][j + c] == num)
                return false;
        }
    }
    return true;
}

bool isPossible(int grid[N][N], int row, int col, int num)
{
    return rowCheck(grid, row, num) &&
           columnCheck(grid, col, num) &&
           boxCheck(grid, row - (row % 3), col - (col % 3), num) &&
           grid[row][col] == UNASSIGNED;
}

void printSudoku(int grid[N][N])
{
    std::cout << "Valid Sudoku" << std::endl;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}
int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solveSudoku(grid))
        printSudoku(grid);
    else
        cout << "Invalid Sudoku";
    return 0;
}