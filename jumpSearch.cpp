#include <iostream>
#include <cmath>
using namespace std;

void jumpSearch(int A[], int n, int e)
{
    int left = 0;
    int right = sqrt(n);
    while (A[right] <= e && right < n)
    {
        left = right;
        right += sqrt(n);
        if (right > n - 1)
            right = n;
    }
    for (int i = left; i < right; i++)
    {
        if (A[i] == e)
        {
            std::cout << "YES";
            return;
        }
    }
    std::cout << "NO";
}
int main()
{
    int n = 8;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int e = 10;
    jumpSearch(A, n, e);
    return 0;
}
