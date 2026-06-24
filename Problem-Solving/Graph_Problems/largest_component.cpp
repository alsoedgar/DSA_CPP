#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // for std::max

using Graph = std::vector<std::vector<int>>;

class GraphProblems {
private:
    // Helper DFS that returns the total size (node count) of the component
    int exploreSize(const Graph& graph, int current, std::unordered_set<int>& visited) {
        // Base case: out of bounds or already visited
        if (current < 0 || current >= graph.size() || visited.count(current)) {
            return 0;
        }

        // Mark the current node as visited
        visited.insert(current);

        // This current node counts as 1 towards the component size
        int size = 1;

        // TODO: Recursively visit neighbors and accumulate their sizes into the total
        for (int neighbor : graph[current]) {
            size += exploreSize(graph, neighbor, visited);
        }

        return size;
    }

public:
    int largestComponent(const Graph& graph) {
        std::unordered_set<int> visited;
        int maxSize = 0;
        int componentSize = 0;

        // Loop through all possible nodes in the graph
        for (int node = 0; node < graph.size(); ++node) {
            // TODO: If the node is unvisited, calculate its component size 
            if(!visited.count(node)){
                componentSize = exploreSize(graph, node, visited);
                maxSize = std::max(maxSize, componentSize);
            }
        }

        return maxSize;
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

    // Total nodes = 8 (0 through 7)
    int n = 8; 

    // Graph Layout:
    // Component 1 (Size 4): 0---1---2
    //                          |
    //                          3
    // Component 2 (Size 2): 4---5
    // Component 3 (Size 2): 6---7
    std::vector<std::vector<int>> edges = {
        {0, 1}, {1, 2}, {1, 3},
        {4, 5},
        {6, 7}
    };
    
    Graph graph = buildGraph(n, edges);
    
    int result = solver.largestComponent(graph);
    std::cout << "Size of the Largest Component: " << result << std::endl;
    std::cout << "Test: " << (result == 4 ? "PASSED (4)" : "FAILED") << std::endl;

    return 0;
}