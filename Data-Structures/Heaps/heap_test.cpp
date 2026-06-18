#include "heap.h"
#include <iostream>
#include <vector>

int main(){
    
    MaxHeap heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(25);
    heap.insert(15);

    std::cout << heap.peekMax() << "\n";
    heap.printAll();
    heap.deleteMax();
    heap.printAll();
    std::cout << heap.peekMax() << "\n";
    

    //create a bigger heap with a vector
    std::vector<int> unsorted_vector = {50, 15, 30, 67, 37, 69};
    MaxHeap new_heap;
    new_heap.heapify(unsorted_vector);
    std::cout << new_heap.peekMax() << "\n";
    new_heap.printAll();


}