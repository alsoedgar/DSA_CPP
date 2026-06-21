#include "adjacency_list.h"
#include <iostream>

int main(){

    Graph adjList(5);

    adjList.addEdge(0, 1);
    adjList.addEdge(0, 2);
    adjList.addEdge(1, 2);
    adjList.addEdge(2, 3);

    adjList.printList();

}