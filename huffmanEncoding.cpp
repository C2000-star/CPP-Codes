#include <iostream>
#include <queue>
#include <vector>
#define N 8
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
void printHuffmanEncoding(Node *root);
struct Compare
{
    bool operator()(Node *i, Node *j)
    {
        return i->val > j->val;
    }
};

void huffmanEncoding(int freq[N])
{
    priority_queue<Node *, vector<Node *>, Compare> f;
    priority_queue<Node *, vector<Node *>, Compare> g;

    for (int i = 0; i < N; i++)
    {
        Node *temp = new Node(freq[i]);
        f.push(temp);
    }
    Node *root;
    while (!f.empty())
    {
        Node *l = f.top();
        f.pop();
        Node *r = f.top();
        f.pop();
        root = new Node(l->val + r->val);
        root->left = l;
        root->right = r;
        f.push(root);
        if (f.size() == 1)
            break;
    }
    printHuffmanEncoding(f.top());
}
void printHuffmanEncoding(Node *root)
{
    if (!root)
        return;
    printHuffmanEncoding(root->left);
    std::cout << root->val << " ";
    printHuffmanEncoding(root->right);
}
int main()
{
    int freq[N] = {2, 3, 7, 1, 4, 5, 6, 9};
    huffmanEncoding(freq);
    return 0;
}