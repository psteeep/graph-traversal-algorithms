#include "breadth_depth-first_search.h"
#include <list>

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    std::cout << v << " ";

    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    std::list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    std::list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

