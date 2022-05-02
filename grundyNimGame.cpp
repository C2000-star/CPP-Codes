#include <iostream>
#include <string.h>
#include <unordered_set>
#define k 3
using namespace std;

int calculateMex(int n, unordered_set<int> set)
{
    if (n == 0)
        return 0;
    int mex = 0;
    while (set.find(mex) != set.end())
        mex++;
    return mex;
}
int grundyNumbers(int n, int grundy[])
{
    if (n <= 0)
        return grundy[0] = 0;
    if (grundy[n] != -1)
        return grundy[n];
    unordered_set<int> set;
    for (int i = 1; i <= k; i++)
    {
        set.insert(grundyNumbers(n - i, grundy));
    }
    grundy[n] = calculateMex(n, set);
    return grundy[n];
}
int main()
{
    int sz = 4;
    int piles[sz] = {3, 4, 5};
    string first = "Alice";
    string second = "Bob";
    int maximum = 8;
    int grundy[maximum + 1];
    memset(grundy, -1, sizeof grundy);
    int XOR = 0;
    for (int i = 0; i < sz; i++)
    {
        XOR ^= grundyNumbers(piles[i], grundy);
    }
    bool win = bool(XOR);
    std::cout << first << " wins: " << win << std::endl;
    std::cout << second << " wins: " << !win;
    return 0;
}
