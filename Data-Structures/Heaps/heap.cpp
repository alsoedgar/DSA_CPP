#include "heap.h"
#include <utility>
#include <stdexcept>
#include <iostream>

//calculate children l = (2i+1) r = (2i+2)
//calculate parent = (i-1)/2

void MaxHeap::maxHeapify(int index){ //bubble down

    while(true){
        int largest = index; //assume parent is largest initially
        int leftChild = (2 * index) + 1;
        int rightChild = (2 * index) + 2;

        //is there a left child? and is it bigger than our current largest
        if(leftChild < heap.size() && heap.at(leftChild) > heap.at(largest)){
            largest = leftChild;
        }
        //is there a right child? and is it bigger than our current largest
        if(rightChild < heap.size() && heap.at(rightChild) > heap.at(largest)){
            largest = rightChild;
        }

        //if largest is parent, then its in place
        if(largest == index){
            break;
        }

        //other wise it swaps largest to the bigger child and updates index to repeat
        std::swap(heap.at(index), heap.at(largest));
        index = largest;
    }
}

void MaxHeap::bubbleUp(){
    int index = heap.size() - 1;

    while(index > 0){
        int parent = (index - 1) / 2;
        if (heap.at(index) > heap.at(parent)) std::swap(heap.at(index), heap.at(parent));
        else break;
        index = parent;
    }
}

void MaxHeap::insert(int val){
    heap.push_back(val);
    bubbleUp();
}

void MaxHeap::deleteMax(){
    if(heap.empty()) return;
    std::swap(heap.at(0), heap.at(heap.size() - 1));
    heap.pop_back();
    maxHeapify(0);
}

int MaxHeap::peekMax(){
    if(heap.empty()) {
        throw std::runtime_error("Heap is empty!");
    }
    return heap.front();
}

void MaxHeap::heapify(std::vector<int> vector){
    heap = vector;

    for(int i = (heap.size() / 2) - 1; i >= 0; i--){
        maxHeapify(i);
    }
} 

void MaxHeap::printAll(){
    for (int element : heap){
        std::cout << element << " ";
    }
    std::cout << "\n";
}
