#include <iostream>
#include <vector>
#include <unordered_set>

using Graph = std::vector<std::vector<int>>;

class GraphProblems {
private:
    // Helper DFS to explore and mark an entire component as visited
    void exploreComponent(const Graph& graph, int current, std::unordered_set<int>& visited) {
        // Base case: out of bounds or already visited
        if (current < 0 || current >= graph.size() || visited.find(current) != visited.end()) {
            return;
        }

        // Mark the current node as visited
        visited.insert(current);
        std::cout << " " << current;

        // Recursively visit all neighbors to "flood fill" this component
        for (int neighbor : graph[current]) {
            exploreComponent(graph, neighbor, visited);
        }
    }

public:
    int connectedComponentsCount(const Graph& graph) {
        std::unordered_set<int> visited;
        int count = 0;

        // Loop through all possible nodes in the graph
        for (int node = 0; node < graph.size(); ++node) {
            // TODO: If the node is unvisited:
            
            if (!visited.count(node)){
                std::cout << "Component " << count << ": ";
                count++;
                exploreComponent(graph, node, visited);
                std::cout << "\n";
            }
            
        }

        return count;
    }
};

Graph buildGraph(int n, const std::vector<std::vector<int>>& edges) {
    Graph graph(n);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return graph;
}

int main() {
    GraphProblems solver;

    // Total nodes = 7 (0 through 6)
    int n = 7; 

    // Graph Layout:
    // Component 1: 0---1---2     Component 2: 3---4     Component 3: 5---6
    std::vector<std::vector<int>> edges = {
        {0, 1}, {1, 2},
        {3, 4},
        {5, 6}
    };
    
    Graph graph = buildGraph(n, edges);
    
    int result = solver.connectedComponentsCount(graph);
    std::cout << "Total Connected Components: " << result << std::endl;
    std::cout << "Test: " << (result == 3 ? "PASSED (3)" : "FAILED") << std::endl;

    return 0;
}