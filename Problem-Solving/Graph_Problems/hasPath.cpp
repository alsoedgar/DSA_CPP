#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

// Definition for the Graph adjacency list using a 2D vector
using Graph = std::vector<std::vector<int>>;

class GraphProblems {
public:
    // TODO: Implement this method using either DFS or BFS
    bool hasPath(const Graph& graph, int src, int dst, std::unordered_set<int>& visited) {

        if(src < 0|| src >= graph.size()) return false; //out of bounds

        if (src == dst) return true; //target found

        if (visited.find(src) != visited.end()) return false; //check cycle (already visited)

        visited.insert(src); //marked current node visited

        for (int neighbor : graph[src]){
            if(hasPath(graph, neighbor, dst, visited)){
                return true;
            }
        }

        return false; //no neighbors lead to dest
    }

    //bfs version
    bool hasPathBFS(const Graph& graph, int src, int dst, std::unordered_set<int>& visited){
        std::queue<int> queue;
        queue.push(src);

        while(!queue.empty()){
            int current = queue.front();
            queue.pop();

            if(visited.count(current)) continue;
            visited.insert(current);

            if(current == dst) return true;

            for (int neighbor : graph.at(current)){
                if (!visited.count(neighbor)){
                    queue.push(neighbor);
                }
            }

        }
            return false;
    }


};

// Helper function to build an undirected graph using a 2D vector
Graph buildGraph(int n, const std::vector<std::vector<int>>& edges) {
    Graph graph(n); // Initialize a vector of size n
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u); // Omit this line if the graph is directed
    }
    return graph;
}

int main() {
    GraphProblems solver;

    // Total number of nodes in our graph (0 through 5)
    int n = 6; 

    // Test Case (Edge List represented as a 2D vector):
    // 1 --- 2     4 --- 5
    // |     |
    // 0 --- 3
    std::vector<std::vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}
    };
    
    Graph graph = buildGraph(n, edges);
    
    // Test 1: Path should exist between 0 and 2
    std::unordered_set<int> visited1;
    bool result1 = solver.hasPath(graph, 0, 2, visited1);
    std::cout << "Path 0 -> 2: " << (result1 ? "PASSED (True)" : "FAILED (False)") << std::endl;

    // Test 2: Path should NOT exist between 0 and 5
    std::unordered_set<int> visited2;
    bool result2 = solver.hasPathBFS(graph, 0, 5, visited2);
    std::cout << "Path 0 -> 5: " << (!result2 ? "PASSED (False)" : "FAILED (True)") << std::endl;

    return 0;
}