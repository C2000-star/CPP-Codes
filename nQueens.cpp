#include <iostream>
#define N 6
using namespace std;

int board[N][N] = {0};

bool isSafeCell(int board[][N], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        if (board[i][c])
            return false;

    i = r;
    j = c;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j])
            return false;
        i--;
        j--;
    }

    i = r;
    j = c;

    while (i >= 0 && j < N)
    {
        if (board[i][j])
            return false;
        i--;
        j++;
    }

    return true;
}

bool nQueens(int board[][N], int i)
{
    if (i == N)
        return true;
    for (int j = 0; j < N; j++)
    {
        if (isSafeCell(board, i, j))
        {
            board[i][j] = 1;
            if (nQueens(board, i + 1))
                return true;
            board[i][j] = 0;
        }
    }
    return false;
}
void printNQueens(int board[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                cout << "Q ";
            else
                cout << "_ ";
        }
        cout << endl;
    }
}
int main()
{
    if (nQueens(board, 0))
        printNQueens(board);
    return 0;
}