/* Heap data structure!
 * There are two types of heaps - a min heap, and a max heap
 * a min heap has each parent as the minimum/lesser value than the children (so the root is the minimum) 
 * and a max heap is the opposite, each parent is greater, so the children are all smaller (root is the maximum)
 * There are two functions a heap uses, heapify, and heapSort which make the heap work!
 * Because of the heap properties, it has an time complexity O(logn) for insert and delete, and O(1) for accessing min or max (access first element) 
 * Additionally, since it's implemented as an array, the space complexity is O(1)
 */

#ifndef HEAP_H
#define HEAP_H
#include <vector>

class MaxHeap{
    private:
    std::vector<int> heap;
    void maxHeapify(int index);
    void bubbleUp();

    public:
    void insert(int val);
    void deleteMax();
    int peekMax();
    void heapify(std::vector<int> vector);
    void printAll();
};

#endif