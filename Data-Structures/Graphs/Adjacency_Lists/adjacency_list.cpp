#include "adjacency_list.h"
#include <iostream>

Graph::Graph(int vertices){
    numVertices = vertices;
    adjList.resize(vertices);
}

//directed graph
void Graph::addEdge(int src, int dst){
    if(src >= 0 && src < numVertices && dst >= 0 && dst < numVertices){ //check if valid 
    adjList[src].push_back(dst);
    }
}

bool Graph::checkEdge(int src, int dst){
    // Safety check
    if (src < 0 || src >= numVertices || dst < 0 || dst >= numVertices) {
        return false; 
    }

    for (int neighbor : adjList[src]){
        if (neighbor == dst){
            return true;
        }
    }
    return false;
}

void Graph::printList(){
    for (int i = 0; i < numVertices; i++){
        std::cout << "Vertex " << i << " -> ";
        
        for (size_t j = 0; j < adjList[i].size(); j++){
            std::cout << adjList[i][j];
            // If it's NOT the last neighbor, print an arrow
            if (j < adjList[i].size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << "\n";
    }
}