//Merge Sort! A sorting algorithm that recursively splits an entire array into single arrays
//then sorts as it merges them back up
//Run time complexity of O(nlogn) but worst case O(n^2)
//Space time complexity of O(n) because it creates subarrays to sort elements *not sorted in place*

#ifndef MERGE_SORT
#define MERGE_SORT
#include <vector>

void mergeSort(std::vector<int>& vec); 
void merge(std::vector<int>& leftArr, std::vector<int>& rightArr, std::vector<int>& vec);

#endif