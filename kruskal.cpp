#include <iostream>
#include <algorithm>
#include <vector>
#define E 10
#define N 6

struct Edge
{
    int src, dest, wt;
};

struct Node
{
    int parent, rank;
};

std::vector<Node> nodes(N);

int findP(int v)
{
    if (nodes[v].parent == -1)
        return v;
    return nodes[v].parent = findP(nodes[v].parent);
}

bool Compare(Edge a, Edge b)
{
    return a.wt < b.wt;
}

void unionOp(int from, int to)
{
    if (nodes[from].rank < nodes[to].rank)
        nodes[from].parent = to;
    else if (nodes[to].rank < nodes[from].rank)
        nodes[to].parent = from;
    else
    {
        nodes[from].parent = to;
        nodes[to].rank++;
    }
}
void printMst(std::vector<Edge> &ans)
{
    for (auto i : ans)
    {
        std::cout << i.src << " " << i.dest << " " << i.wt << std::endl;
    }
}
void kruskal(std::vector<Edge> &edges, std::vector<Node> &nodes)
{
    sort(edges.begin(), edges.end(), Compare);
    std::vector<Edge> ans;
    int i = 0, j = 0;
    while (i < N - 1 && j < E)
    {
        int from = findP(edges[j].src);
        int to = findP(edges[j].dest);

        if (from == to)
        {
            j++;
            continue;
        }

        unionOp(from, to);
        ans.push_back(edges[j]);
        i++;
    }
    printMst(ans);
}
int main()
{
    std::vector<Edge> edges;
    for (int i = 0; i < E; i++)
    {
        Edge temp;
        int from, to, w;
        std::cin >> from >> to >> w;
        temp.src = from;
        temp.dest = to;
        temp.wt = w;
        edges.push_back(temp);
    }

    for (int i = 0; i < N; i++)
    {
        nodes[i].parent = -1;
        nodes[i].rank = 0;
    }

    kruskal(edges, nodes);
    return 0;
}
