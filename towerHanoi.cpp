#include <iostream>
using namespace std;

void towerOfHanoi(int n, char S, char T, char I)
{
    if (n == 1)
    {
        std::cout << "Move disc " << n << " from " << S << " to " << T << std::endl;
        return;
    }
    if (n > 1)
    {
        towerOfHanoi(n - 1, S, I, T);
        std::cout << "Move disc " << n << " from " << S << " to " << T << std::endl;
        towerOfHanoi(n - 1, I, T, S);
    }
}
int main()
{
    towerOfHanoi(4, 'S', 'T', 'I');
    return 0;
}