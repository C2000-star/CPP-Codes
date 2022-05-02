#include <iostream>
#define N 4
using namespace std;
int main()
{
    int a = 1, b = 1, c = 2, ans = 0;
    for (int i = 3; i <= N; i++)
    {
        ans = a + b + c;
        a = b;
        b = c;
        c = ans;
    }
    std::cout << ans << std::endl;
    return 0;
}