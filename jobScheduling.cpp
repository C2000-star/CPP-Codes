#include <iostream>
#include <vector>
#include <queue>
#define N 6
using namespace std;

int maxJobs(const int jobs[N][2])
{
    int count = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> j;
    for (int i = 0; i < N; i++)
    {
        j.push(make_pair(jobs[i][1], jobs[i][0]));
    }
    auto prev = j.top();
    j.pop();
    int endTime = prev.first;
    while (!j.empty())
    {
        auto curr = j.top();
        j.pop();
        int startTime = curr.second;
        if (startTime >= endTime)
        {
            count++;
            prev = curr;
            endTime = prev.first;
        }
    }
    return count;
}
int main()
{
    int jobs[N][2] = {
        {0, 2},
        {3, 10},
        {6, 12},
        {11, 13},
        {12, 14},
        {11, 15}};

    std::cout << maxJobs(jobs) << std::endl;
    return 0;
}