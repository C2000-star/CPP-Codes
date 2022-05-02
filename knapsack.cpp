#include <iostream>
#define N 5
using namespace std;
int c = 10;
int temp[10][N + 1] = {0};
int knapsack(int ks[N][2], int c, int i)
{
    if (temp[c][i])
        return temp[c][i];
    if (i > N)
        return temp[c][i] = 0;
    else if (c < ks[i][1])
        return temp[c][i] = knapsack(ks, c, i + 1);
    else
        return temp[c][i] = max(knapsack(ks, c, i + 1), ks[i][0] + knapsack(ks, c - ks[i][1], i + 1));
}
int main()
{
    int ks[N][2] = {
        {3, 2},
        {5, 4},
        {2, 2},
        {3, 3},
        {4, 1}};

    cout << "Max Profit is: " << knapsack(ks, c, 0);
    return 0;
}