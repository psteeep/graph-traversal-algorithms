#include <iostream>
#include <cmath>
#include <list>


class Graph {
private:

    int V; 

    std::list<int>* adj;

    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V); 
    void addEdge(int v, int w);
    void DFS(int v);
    void BFS(int s);
};
