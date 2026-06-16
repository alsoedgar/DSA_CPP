#include "quick_sort.h"
#include <vector>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int> &arr, int low, int high){
    int i = low - 1;
    int pivot = high;

    for(int j = low; j < pivot; j++){
        if(arr.at(j) < arr.at(pivot)){
            i++;
            swap(arr.at(i), arr.at(j));
        }   
    }

    swap(arr.at(i+1), arr.at(pivot));

    return i+1;
}

void quickSortRecursion(std::vector<int>& arr, int low, int high){
    if (low < high){
    int pivot = partition(arr, low, high); //find pivot

    quickSortRecursion(arr, low, pivot-1); //recursively split up array
    quickSortRecursion(arr, pivot + 1, high);
    }
}