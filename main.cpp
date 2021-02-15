#include <iostream>
#include "breadth_depth-first_search.h"
#include "graph_algo.h"

int main() {
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS(2);
  
    std::cout << std::endl;

    std::cout << "Following is Depth First Traversal"
        " (starting from vertex 2) \n";
    g.DFS(2);

    std::cout << std::endl;

    GraphAlgo algo;

    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                       { 2, 0, 3, 8, 5 },
                       { 0, 3, 0, 0, 7 },
                       { 6, 8, 0, 0, 9 },
                       { 0, 5, 7, 9, 0 } };
  
    algo.primMST(graph);
    
    
    
    int graph1[D][D] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    algo.dijkstra(graph1, 0);

    int graph2[F][F] = { {0, 16, 13, 0, 0, 0},
                       {0, 0, 10, 12, 0, 0},
                       {0, 4, 0, 0, 14, 0},
                       {0, 0, 9, 0, 0, 20},
                       {0, 0, 0, 7, 0, 4},
                       {0, 0, 0, 0, 0, 0}
    };

    std::cout << "The maximum possible flow is " << algo.fordFulkerson(graph2, 0, 5);
    return 0;
}