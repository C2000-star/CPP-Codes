#include <iostream>
#include <vector>
#define N 4
#define k 2
using namespace std;
int main()
{
    vector<int> d(N, INT_MAX);
    vector<int> paid{0, 3, 4, 5};
    d[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < i + k + 1; j++)
        {
            d[j] = min(d[j], d[i] + paid[j]);
        }
    }
    std::cout << d[N - 1] << std::endl;
    return 0;
}