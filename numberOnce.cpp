#include <iostream>
#define N 7

using namespace std;

int main()
{
    int cntZ, cntO, res = 0;
    int arr[N] = {8, 8, 5, 5, 5, 8, 3};
    for (int i = 0; i < 32; i++)
    {
        cntO = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[j] & (1 << i))
                cntO++;
        }
        if (cntO % 3)
            res |= (1 << i);
    }
    std::cout << "The number that appears only once is: " << res;
    return 0;
}