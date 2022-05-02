#include <iostream>
#define N 3
using namespace std;

void nimGame(int arr[], string first, string second)
{
    int y = 0;
    for (int i = 0; i < N; i++)
    {
        y ^= arr[i];
    }
    if (!y)
    {
        std::cout << second << " wins the game!";
    }
    else
    {
        std::cout << first << " wins the game";
    }
}
int main()
{
    int arr[3] = {3, 2, 1};
    nimGame(arr, "Alice", "Bob");
    return 0;
}