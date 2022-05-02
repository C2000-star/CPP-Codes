#include <iostream>
#include <queue>
#define N 7
#define k 3
struct Node
{
    int val, index;
};
class Compare
{
public:
    bool operator()(Node a, Node b)
    {
        return a.val < b.val;
    }
};
void slidingWindow(int arr[])
{
    std::priority_queue<Node, std::vector<Node>, Compare> pq;
    std::vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        Node temp;
        temp.val = arr[i];
        temp.index = i;
        pq.push(temp);
        if ((k - i - 1) <= 0)
        {
            Node temp;
            temp = pq.top();
            pq.pop();
            ans.push_back(temp.val);
        }
    }
    for (int e : ans)
        std::cout << e << " ";
}
int main()
{
    int arr[N] = {1, 5, 3, 4, 5, 6, 7};
    slidingWindow(arr);
    return 0;
}