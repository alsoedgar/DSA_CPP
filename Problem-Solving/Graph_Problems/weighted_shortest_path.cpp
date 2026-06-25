#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>

using WeightedGraph = std::vector<std::vector<std::pair<int, int>>>;

class GraphAlgorithms {
public:
    int shortestPath(const WeightedGraph& graph, int src, int dst) {
        // TODO: Implement your Dijkstra code here!
        std::vector<int> dist (graph.size(), INT_MAX); //stores shortest distance for each vertex
                                                //i.e. dist.at(5) gives you curr shortest distance
        
        std::priority_queue<std::pair<int, int>, //priority queue
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int,int>>> priorityQueue;  
        
        //push src into queue
        dist[src] = 0;
        priorityQueue.push({0, src});

        while(!priorityQueue.empty()){
            auto [currentDistance, node] = priorityQueue.top();
            priorityQueue.pop();

            if (node == dst) return currentDistance; //reached the node

            if(currentDistance > dist[node]) continue; //skip dont change anything if currentDistance isnt shortest path
            
            for (const auto& edge : graph.at(node)){
                auto [neighbor, weight] = edge;

                int accumulatedDistance = currentDistance + weight;

                if(accumulatedDistance < dist[neighbor]){
                dist[neighbor] = accumulatedDistance;
                priorityQueue.push({accumulatedDistance, neighbor});
                }
            }
        }
        return -1; //not found
    }
};

WeightedGraph buildGraph(int n, const std::vector<std::vector<int>>& edges) {
    WeightedGraph graph(n);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    return graph;
}

int main() {
    GraphAlgorithms solver;
    int n = 7; 

    std::vector<std::vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 3, 6},
        {1, 4, 2},
        {2, 1, 1},
        {2, 3, 2},
        {3, 5, 1},
        {4, 3, 1},
        {4, 6, 7},
        {5, 6, 2}
    };

    WeightedGraph graph = buildGraph(n, edges);

    int result = solver.shortestPath(graph, 0, 6);
    
    std::cout << "--- YOUR DIJKSTRA TEST ---" << std::endl;
    std::cout << "Calculated Distance: " << result << std::endl;
    
    // Once you run your code, check it against the correct answer below!
    // Hint: Watch out for the path through Node 4 vs Node 3!
    
    return 0;
}