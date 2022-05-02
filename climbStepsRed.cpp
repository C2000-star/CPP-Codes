#include <iostream>
#define N 4
#define k 3
using namespace std;
int main()
{
    bool red[N] = {0, 1, 0, 0};
    int d[k] = {0};
    d[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < k; j++)
        {
            if (i < j)
                continue;
            if (red[i - 1])
                d[i % k] = 0;
            else
                d[i % k] += d[(i - j) % k];
        }
    }
    std::cout << d[N % k] << std::endl;
    return 0;
}