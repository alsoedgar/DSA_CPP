#include <iostream>
#include "prim.h"

// Helper function to build a weighted undirected graph
WeightedGraph buildUndirectedGraph(int n, const std::vector<std::vector<int>>& edges) {
    WeightedGraph graph(n);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // Must be bidirectional for undirected graphs
    }
    return graph;
}

int main() {
    PrimMST solver;
    int n = 4; // Nodes 0 through 3

    // Graph Layout:
    //      (1)
    //    0 ---- 1
    //    |    / |
    // (4)|  /(3)| (5)
    //    | /    |
    //    2 ---- 3
    //       (2)
    //
    // Optimal MST Selection should be:
    // Edge (0-1) weight 1
    // Edge (1-2) weight 3
    // Edge (2-3) weight 2
    // Total Expected Weight: 1 + 3 + 2 = 6
    std::vector<std::vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 5},
        {2, 3, 2}
    };

    WeightedGraph graph = buildUndirectedGraph(n, edges);

    int totalMSTWeight = solver.calculateMSTWeight(graph);

    std::cout << "--- PRIM'S MST TEST ---" << std::endl;
    std::cout << "Calculated MST Total Weight: " << totalMSTWeight << std::endl;
    std::cout << "Test: " << (totalMSTWeight == 6 ? "PASSED (6)" : "FAILED") << std::endl;

    return 0;
}