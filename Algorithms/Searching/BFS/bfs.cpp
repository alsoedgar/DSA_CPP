#include <iostream>
#include <vector>
#include <queue> // Don't forget to include this!

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void addEdge(int src, int dst) {
        if (src >= 0 && src < numVertices && dst >= 0 && dst < numVertices) {
            adjMatrix[src][dst] = 1;
        }
    }

    // TODO: Implement the BFS Traversal
    void BFS(int startVertex) {
        // 1. Create a visited vector of size numVertices initialized to false
        std::vector<bool> visited(adjMatrix[startVertex].size(), false);
        
        // 2. Create a std::queue<int> to hold vertices to visit
        std::queue<int> queue;

        // 3. Mark startVertex as visited and push it into the queue
        visited[startVertex] = true;
        queue.push(startVertex);
        
        std::cout << "BFS Traversal starting from " << startVertex << ": ";

        while(!queue.empty()){
            int currentVertex = queue.front();
            queue.pop();
            std::cout << currentVertex << " ";

            for (int i = 0; i < numVertices; i++){
                if(adjMatrix[currentVertex][i] == 1 && !visited[i]){
                    queue.push(i);
                    visited[i] = true;
                }
            }
        }
        
        std::cout << "\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    
       /*
        0 1 1 0 0 
        0 0 0 1 1 
        0 0 0 0 1 
        1 0 0 0 0 
        0 0 0 0 0
    */

    // Test BFS
    // Expected Output Sequence: 0 1 2 3 4
    g.BFS(0); 

    return 0;
}