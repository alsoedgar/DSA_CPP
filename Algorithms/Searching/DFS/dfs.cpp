#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    // 2D vector for the Adjacency Matrix
    std::vector<std::vector<int>> adjMatrix;

    // TODO: Implement this helper function for recursion
    void DFSHelper(int src, std::vector<bool>& visited) {
        // 1. Mark the current vertex as visited and print it
        if(visited[src]){
            return;
        }
        else{
            visited[src] = true;
            std::cout << src << " ";
        } 

        for (int i = 0; i < adjMatrix[src].size(); i++){
            if(adjMatrix[src][i] == 1 && !visited[i]){
                DFSHelper(i, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    // Add edge for a directed graph
    void addEdge(int src, int dst) {
        if (src >= 0 && src < numVertices && dst >= 0 && dst < numVertices) {
            adjMatrix[src][dst] = 1;
        }
    }

    // Print the matrix
    void printMatrix() {
        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    // TODO: Implement the main DFS wrapper function
    void DFS(int startSrc) {
        // 1. Create a visited vector of size numVertices initialized to false
        std::vector<bool> visited(adjMatrix[startSrc].size());
        
        std::cout << "DFS Traversal: \n";
        
        DFSHelper(startSrc, visited);
        
        std::cout << "\n";
    }
};

int main() {
    // Creating the challenge graph with 5 vertices (0 to 4)
    Graph g(5);

    // Adding the challenge edges
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

    // Verify the matrix setup
    g.printMatrix();

    // Test your DFS implementation here
    std::cout << "--- Testing DFS ---\n";
    g.DFS(0); // Expected output sequence: 0 1 3 4 2

    return 0;
}