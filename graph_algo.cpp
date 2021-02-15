#include "graph_algo.h"
#include <limits.h> 
#include <string.h> 
#include <queue> 

int GraphAlgo::minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void GraphAlgo::printMST(int parent[], int graph[V][V])
{
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void GraphAlgo::primMST(int graph[V][V])
{

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++)
    {  
        int u = GraphAlgo::minKey(key, mstSet);

        mstSet[u] = true;
     
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    GraphAlgo::printMST(parent, graph);
}



// Dijkstra

int GraphAlgo::minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < D; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void GraphAlgo::printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void GraphAlgo::dijkstra(int graph[D][D], int src)
{
 
    for (int i = 0; i < D; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < D - 1; count++) {
        int u = GraphAlgo::minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < D; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    GraphAlgo::printSolution(dist);
}




//Ford-Fulkerson Algorithm

bool GraphAlgo::bfs(int rGraph[F][F], int s, int t, int parent[])
{
    
    bool visited[F];
    memset(visited, 0, sizeof(visited));

   
    std::queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

   
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < F; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    
    return (visited[t] == true);
}


int GraphAlgo::fordFulkerson(int graph[F][F], int s, int t)
{
    int u, v;

    
    int rGraph[F][F];   
    for (u = 0; u < F; u++)
        for (v = 0; v < F; v++)
            rGraph[u][v] = graph[u][v];

    int parent[F];  
    int max_flow = 0;  

    while (bfs(rGraph, s, t, parent))
    {
        
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = std::min(path_flow, rGraph[u][v]);
        }

        
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

      
        max_flow += path_flow;
    }

   
    return max_flow;
}













