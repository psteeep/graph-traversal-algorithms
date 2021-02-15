#include <iostream>
#include <cmath>

#define V 5 
#define D 9 
#define F 6 

class GraphAlgo {
private:
	int parent[V];
	int key[V];
	bool mstSet[V];

	int dist[D];
	bool sptSet[D]; 
	
public:
	// Prim's algorithm
	int minKey(int key[], bool mstSet[]);
	void printMST(int parent[], int graph[V][V]);
	void primMST(int graph[V][V]);

	//Dijkstra's algorithm

	int minDistance(int dist[], bool sptSet[]);
	void printSolution(int dist[]);
	void dijkstra(int graph[D][D], int src);

	//Ford-Fulkerson Algorithm
	bool bfs(int rGraph[F][F], int s, int t, int parent[]);
	int fordFulkerson(int graph[F][F], int s, int t);

};