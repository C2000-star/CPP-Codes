#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;

        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};
vector<int> res;
vector<int> inOrder(Node *root)
{
    stack<Node *> nodes;
    nodes.push(root);
    Node *it = root;
    while (1)
    {
        if (it == NULL)
        {
            if (nodes.empty())
                break;
            it = nodes.top();
            nodes.pop();
            res.push_back(it->data);
            it = it->right;
        }
        else
        {
            nodes.push(it);
            it = it->left;
        }
    }
    return res;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    vector<int> res;
    /* 4 becomes left child of 2
               1
            /     \
           2       3
          / \     / \
         4  NULL NULL NULL
        / \
     NULL NULL
    */
    res = inOrder(root);
    for (int i = 0; i < 4; i++)
    {
        std::cout << res[i];
    }
    return 0;
}