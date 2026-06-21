//Adjacency matrix is a 2D array to store 1's/0's  to represent edges
//There are two ways to make graphs, directed and undirected
// # of rows = # of unique nodes
// # of columns # of unique nodes
//The runtime complexity to check an edge is O(1)
//However, the space complexity is O(v^2) (because size is based off of nodes^2)

#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H
#include <iostream>
#include <vector>

class Graph{
    private:
    int numVertices;
    //2D vector set to 0 (no edges yet)
    std::vector<std::vector<int>> adjMatrix;

    public:
    //initialize matrix with V x V dimensions
    Graph(int vertices){
        numVertices = vertices;
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void addEdge(int src, int dst);
    bool checkEdge(int src, int dst);
    void printMatrix();


};



#endif