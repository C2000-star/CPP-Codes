#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int n;
    Node *l;
    Node(int x) : n(x), l(NULL) {}
};
map<int, Node *> mp;
int main()
{
    mp[2] = new Node(1);
    if (mp[2] == NULL)
    {
        std::cout << "Not Okay";
    }
    else
    {
        std::cout << "Okay";
    }
    return 0;
}
