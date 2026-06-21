#include "adjacency_matrix.h"
#include <iostream>

//directed graph 
void Graph::addEdge(int src, int dst){
    adjMatrix[src][dst] = 1;
}

bool Graph::checkEdge(int src, int dst){
    return (adjMatrix[src][dst] == 1);
}

void Graph::printMatrix(){
    if(adjMatrix.size() == 0) return;

    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            std::cout << checkEdge(i, j) << " ";
        }
        std::cout << "\n";
    }
}