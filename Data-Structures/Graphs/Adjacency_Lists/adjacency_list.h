//An array/arrayList of linkedlists
//Each linked list has a unique node at the head
//all adjacent neighbors to that node are added to that nodes linked list
//runtime complexity of O(v)
//space time complexity of O(v + e)

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include <vector>

class Graph{
    private:
    int numVertices;
    std::vector<std::vector<int>> adjList;
    public:
    Graph(int vertices);
    void addEdge(int src, int dst);
    bool checkEdge(int src, int dst);
    void printList();
};


#endif