#include <iostream>
#include "dijkstra.h"

// Helper function to build a weighted undirected graph
WeightedGraph buildWeightedGraph(int n, const std::vector<std::vector<int>>& edges) {
    WeightedGraph graph(n);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // Omit this line if you want a directed graph
    }
    return graph;
}

int main() {
    GraphAlgorithms solver;
    int n = 5; // Nodes 0 through 4

    // Graph Layout:
    //      (1)
    //    0 ---- 1
    //    | \    | (2)
    // (6)|  \(3)|
    //    |   \  |
    //    3 ---- 2
    //       (1)
    //
    // Node 4 is completely isolated.
    //
    // Format: {node1, node2, weight}
    std::vector<std::vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 3},
        {1, 2, 2},
        {0, 3, 6},
        {2, 3, 1}
    };

    WeightedGraph graph = buildWeightedGraph(n, edges);

    // Test 1: Shortest path from 0 to 3
    // Path options:
    // Direct: 0 -> 3 (cost 6)
    // Indirect: 0 -> 1 -> 2 -> 3 (cost 1 + 2 + 1 = 4) <-- Dijkstra should pick this!
    int result1 = solver.shortestPath(graph, 0, 3);
    std::cout << "Shortest path 0 -> 3: " << result1 << std::endl;
    std::cout << "Test 1: " << (result1 == 4 ? "PASSED (4)" : "FAILED") << std::endl;

    // Test 2: Path to isolated node 4
    int result2 = solver.shortestPath(graph, 0, 4);
    std::cout << "Shortest path 0 -> 4: " << result2 << std::endl;
    std::cout << "Test 2: " << (result2 == -1 ? "PASSED (-1)" : "FAILED") << std::endl;

    return 0;
}