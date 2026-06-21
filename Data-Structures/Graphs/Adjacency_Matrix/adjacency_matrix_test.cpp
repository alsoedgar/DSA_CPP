#include "adjacency_matrix.h"
#include <iostream>

int main(){
    Graph matrix(4);

    matrix.addEdge(0, 1);
    matrix.addEdge(0, 2);
    matrix.addEdge(1, 2);
    matrix.addEdge(2, 3);
    
    matrix.printMatrix();
    return 0;
}