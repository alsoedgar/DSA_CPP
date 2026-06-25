#include "prim.h"
#include <queue>
#include <climits>

int PrimMST::calculateMSTWeight(const WeightedGraph& graph) {
    if (graph.empty()) return 0;

    int totalWeight = 0;
    int nodesVisitedCount = 0;

    // 1. Visited array to lock down nodes once they are officially added to our MST
    std::vector<bool> inMST(graph.size(), false);

    // 2. Ledger tracking the cheapest edge cost to connect each node to the tree
    std::vector<int> minEdgeCost(graph.size(), INT_MAX);

    // 3. Min-Heap Priority Queue
    // Stores pairs of format: {edgeWeight, nodeID}
    std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>, 
                        std::greater<std::pair<int, int>>> pq;

    // 4. Seed the algorithm with Node 0
    minEdgeCost[0] = 0;
    pq.push({0, 0}); // Costing 0 to hook up node 0 to itself

    while (!pq.empty()) {
        
        // E. Loop through neighbors: If a neighbor is not yet inMST AND the single connection weight 
        //    is strictly cheaper than its recorded minEdgeCost, update minEdgeCost[neighbor] and push it to pq.
        auto[edgeWeight, currNode] = pq.top();
        pq.pop();

        if(inMST.at(currNode) == true) continue;  // Check if currentNode is already inMST. If yes, continue (skip stale data)

        // Mark currentNode as inMST = true, increment nodesVisitedCount, and add edge weight to totalWeight.
        inMST.at(currNode) = true;
        nodesVisitedCount++;
        totalWeight += edgeWeight;

        for (auto [neighbor, weight] : graph.at(currNode)){
            if (!inMST.at(neighbor) && weight < minEdgeCost.at(neighbor)){
                minEdgeCost[neighbor] = weight;
                pq.push({weight, neighbor});
            }
        }
    }

    // Guard rail: If we couldn't reach all vertices, an MST is impossible
    return (nodesVisitedCount == graph.size()) ? totalWeight : -1;
}