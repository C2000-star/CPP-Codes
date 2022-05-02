// #include <iostream>
// #include <vector>
// #define N 6
// int maxFlow = 0;
// bool visited[N] = {0, 0, 0, 0, 0, 0};
// void minCut(int graph[][N], std::vector<int> adj[], int s, int minEdge)
// {
//     printf("void minCut(graph, adj, %d,%d)\n", s, minEdge);
//     visited[s] = 1;
//     printf("visited[%d] = 1 \n", s);
//     if (s == N - 1)
//     {
//         maxFlow += minEdge;
//         printf("maxFlow = %d", maxFlow);
//         return;
//     }

//     for (int e : adj[s])
//     {
//         if (!visited[e] && graph[s][e])
//         {
//             minEdge = std::min(minEdge, graph[s][e]);
//             printf("minEdge: %d \n", minEdge);
//             minCut(graph, adj, e, minEdge);
//             printf("minCut(graph, adj, %d, %d) \n", e, minEdge);
//             graph[s][e] -= minEdge;
//             printf("graph[%d][%d] = %d\n", s, e, graph[s][e]);
//             visited[e] = 0;
//             if(s!=0)
//                 break;
//         }
//     }

//     return;
// }
// int main()
// {
//     std::vector<int> adj[N];
//     int graph[N][N];
//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//             graph[i][j] = 0;

//     graph[0][1] = 16;
//     graph[0][2] = 13;
//     graph[1][2] = 10;
//     graph[1][3] = 12;
//     graph[2][4] = 14;
//     graph[2][1] = 4;
//     graph[3][2] = 9;
//     graph[3][5] = 20;
//     graph[4][3] = 7;
//     graph[4][5] = 4;

//     for (int i = 0; i < N - 1; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             if (graph[i][j])
//             {
//                 adj[i].push_back(j);
//             }
//         }
//     }
//     int A = 5;
//     minCut(graph, adj, 0, INT_MAX);
//     std::cout << "Maximum Flow is: " << maxFlow << std::endl;
//     return 0;
// }