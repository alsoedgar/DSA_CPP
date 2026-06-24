#include "dijkstra.h"
#include <queue>
#include <climits>

int GraphAlgorithms::shortestPath(const WeightedGraph& graph, int src, int dst) {
    // 1. Guard rails: bounds check
    if (src < 0 || src >= graph.size() || dst < 0 || dst >= graph.size()) {
        return -1;
    }

    // 2. Track the minimum distance found so far to each node
    // Initialize all distances to infinity (INT_MAX)
    std::vector<int> dist(graph.size(), INT_MAX);

    // 3. Min-Heap Priority Queue
    // Stores pairs of format: {accumulatedDistance, nodeID}
    // std::greater ensures the smallest distance is always at the top (.top())
    std::priority_queue<std::pair<int, int>,  
                        std::vector<std::pair<int, int>>, 
                        std::greater<std::pair<int, int>>> pq; 

    // 4. Initialize the source node
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        // A & B: Extract and pop the top element
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        // C: Destination reached
        if(currentNode == dst){
            return currentDistance;
        }
        // D: Optimization check
        if(currentDistance > dist[currentNode]) continue;

        // E: Loop through weighted neighbors
        for (std::pair<int,int> edge : graph[currentNode]){
            int neighbor = edge.first;
            int edgeWeight = edge.second;

            int newDistance = currentDistance + edgeWeight;

            //relaxation step
            if(newDistance < dist[neighbor]){
                dist[neighbor] = newDistance;
                pq.push({newDistance, neighbor});
            }
        }
    }

    return -1; // Destination is unreachable
}