#include <iostream>
#include <cmath>
#include <list>

class Graph {
private:
    int V;
    std::list<int>* adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

