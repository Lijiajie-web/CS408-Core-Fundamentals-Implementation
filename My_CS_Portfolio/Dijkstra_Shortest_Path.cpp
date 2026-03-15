/**
 * @file Dijkstra_Shortest_Path.cpp
 * @brief Implementation of Dijkstra's Algorithm using Adjacency Matrix
 * @note Developed during CS408 and Discrete Mathematics preparation.
 *       Demonstrates understanding of Graph Theory and Greedy Algorithms.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 9 // Number of vertices in the graph

// A utility function to find the vertex with minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(int graph[V][V], int src) {
    vector<int> dist(V, INT_MAX); // Output array. dist[i] holds the shortest distance
    vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included

    dist[src] = 0; // Distance of source vertex from itself is always 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true; // Mark the picked vertex as processed

        // Update dist value of the adjacent vertices
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << "\n";
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph, 0);
    return 0;
}