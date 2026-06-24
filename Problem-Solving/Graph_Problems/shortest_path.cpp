#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <utility> // for std::pair

using Graph = std::vector<std::vector<int>>;

class GraphProblems {
public:
    int shortestPath(const Graph& graph, int src, int dst) {
        // Guard rails: out of bounds check
        if (src < 0 || src >= graph.size() || dst < 0 || dst >= graph.size()) {
            return -1;
        }

        // Queue stores pairs of {currentNode, currentDistance}
        std::queue<std::pair<int, int>> q;
        std::unordered_set<int> visited;

        // Initialize the BFS
        q.push({src, 0});
        visited.insert(src);

        while (!q.empty()) {
        
            std::pair<int,int> current = q.front();
            q.pop();
        
            int currentNode = current.first;
            int currentDistance = current.second;

            if (currentNode == dst) return currentDistance;

            for (int neighbor : graph[currentNode]){
                if(!visited.count(neighbor)){
                visited.insert(neighbor);
                q.push({neighbor, currentDistance + 1});
                }
            }
            
        }

        return -1; // Path not found
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

    // Total nodes = 6 (0 through 5)
    int n = 6; 

    // Graph Layout:
    //      1 --- 2
    //    /        \
    //  0 ---------- 3 --- 4     5 (Isolated)
    //
    // There are two paths from 0 to 3:
    // Path A: 0 -> 1 -> 2 -> 3  (3 edges)
    // Path B: 0 -> 3            (1 edge)
    std::vector<std::vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3},
        {0, 3}, {3, 4}
    };
    
    Graph graph = buildGraph(n, edges);
    
    // Test 1: Shortest path from 0 to 4 should be 2 edges (0 -> 3 -> 4)
    int result1 = solver.shortestPath(graph, 0, 4);
    std::cout << "Shortest path 0 -> 4: " << result1 << " edges" << std::endl;
    std::cout << "Test 1: " << (result1 == 2 ? "PASSED (2)" : "FAILED") << std::endl;

    // Test 2: Path to isolated node 5 should return -1
    int result2 = solver.shortestPath(graph, 0, 5);
    std::cout << "Shortest path 0 -> 5: " << result2 << std::endl;
    std::cout << "Test 2: " << (result2 == -1 ? "PASSED (-1)" : "FAILED") << std::endl;

    return 0;
}