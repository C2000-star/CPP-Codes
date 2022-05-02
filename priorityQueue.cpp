#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int A[] = {1, 9, 9, 9, 8, 7, 11, 8};
    std::priority_queue<int, vector<int>, greater<int>> prior;

    int B = 3;

    for (int e : A)
    {
        prior.push(e);
        if (prior.size() > B)
            prior.pop();
    }

    while (prior.size() > 0)
    {
        std::cout << prior.top() << " ";
        prior.pop();
    }
}