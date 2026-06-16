//Quick Sort! A recursive sorting algorithm that
//splits an array into sub arrays, then sorts them in place!
//Uses recursion to sort the sub array greater than, and smaller than the original pivot
//and uses two variables (i, j) to compare keep track of where the pivot goes
//and have elements greater than it on the right side, and less than it on the left! 
//time complexity of O(nlogn) for time comp[lexity, but has worst case o(n^2) if sorted
//in place sorting so space complexity is o(1) IF implemented iteratively
//else o(logn) space complexity because of recursion call stack

#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <vector>

void quickSortRecursion(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);
void swap(int &a, int &b);

#endif