#include <iostream>
#include <vector>
#define N 9
using namespace std;

void climbPaidStairsPath(int paid[])
{
    vector<int> path;
    int from[N + 1];
    for (int i = 2; i <= N; i++)
    {
        paid[i] = min(paid[i - 1], paid[i - 2]) + paid[i];
        if (paid[i - 1] < paid[i - 2])
        {
            from[i] = i - 1;
        }
        else
        {
            from[i] = i - 2;
        }
    }
    for (int i = N - 1; i >= 0; i = from[i])
    {
        path.push_back(i);
        if (i == 0)
            break;
    }
    for (int i = path.size() - 1; i >= 0; i--)
        std::cout << path[i] << " ";
}
int main()
{
    int paid[N] = {0, 3, 2, 4, 6, 1, 1, 5, 3};
    climbPaidStairsPath(paid);
    return 0;
}
