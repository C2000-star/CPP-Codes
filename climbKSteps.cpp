#include <iostream>
#define N 4
#define k 3
using namespace std;
int main()
{
    int d[k] = {0};
    d[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < k; j++)
        {
            if (i < j)
                continue;
            d[i % k] += d[(i - j) % k];
        }
    }
    std::cout << d[N % k] << std::endl;
    return 0;
}