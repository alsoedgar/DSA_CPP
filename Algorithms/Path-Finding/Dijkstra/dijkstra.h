/**
 * Dijkstra's Algorithm
 * Dijkstra's algorithm finds the shortest path (minimum total edge weight) 
 * from a single source node to all other nodes (or a specific destination node) 
 * in a weighted, directed or undirected graph with non-negative edge weights.
 * TIME COMPLEXITY of O((V + E) * log V) where V is the number of vertices and E is the number of edges.
 * Why? Each vertex and edge is explored. When pushing or popping from the min-heap 
 * (priority queue) to find the next minimum-cost node, it takes O(log V) time to 
 * re-heapify.
 * SPACE COMPLEXITY is O(V + E) to store the graph, and O(V) for the distance tracking vector and min-heap.
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>

// Graph representation: vector of vectors holding pairs of {neighbor, weight}
using WeightedGraph = std::vector<std::vector<std::pair<int, int>>>;

class GraphAlgorithms {
public:
    int shortestPath(const WeightedGraph& graph, int src, int dst);
};

#endif // DIJKSTRA_H