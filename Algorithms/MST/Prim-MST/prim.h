/**
 * Prim's Algorithm (Minimum Spanning Tree)
 * Prim's algorithm finds a Minimum Spanning Tree (MST) for a weighted, 
 * undirected graph. It starts from an arbitrary seed vertex and grows the 
 * tree one vertex at a time by greedily swallowing the absolute cheapest 
 * edge that connects a node inside the tree to a node outside the tree.
 * * TIME COMPLEXITY is O((V + E) * log V) using a binary heap (std::priority_queue).
 * - Why? Every vertex is extracted from the heap once, and every edge can 
 * potentially trigger an element insertion or re-heapification step costing O(log V).
 * SPACE COMPLEXITY is O(V + E) to house the adjacency list, and O(V) for the priority queue and tracking sets.
 */

#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <utility>

using WeightedGraph = std::vector<std::vector<std::pair<int, int>>>;

class PrimMST {
public:
    int calculateMSTWeight(const WeightedGraph& graph);
};

#endif // PRIM_H