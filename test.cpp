#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int repeatedNumber(int A[])
{
    int i, xor1 = 0, xor2 = 1;
    for (i = 0; i < 5; i++)
    {
        xor1 ^= A[i];
        std::cout << xor1 << " ";
    }
    int n = 5;
    for (i = 2; i <= (n - 1); i++)
    {
        xor2 ^= i;
    }

    int repeat;
    repeat = xor1 ^ xor2;

    return repeat;
}
int main()
{
    int A[5] = {1, 1, 2, 3, 2};
    
    int ans = repeatedNumber(A);
    std::cout << std::endl;
    std::cout<<ans;
    return 0;
}
