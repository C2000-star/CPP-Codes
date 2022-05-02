#include <iostream>
#define N 3

using namespace std;

int main()
{
    int p, cntZ, cntO, res = 0;
    int arr[N] = {5, 3, 9};
    for (int i = 0; i < 31; i++)
    {
        cntZ = 0, cntO = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[j] & (1 << i))
                cntO++;
            else
                cntZ++;
        }
        p = cntZ * cntO;
        res += (1 << i) * p;
    }
    std::cout << "Total sum of all XOR pairs: " << res;
    return 0;
}