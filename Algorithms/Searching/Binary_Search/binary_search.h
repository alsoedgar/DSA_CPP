/*
 * Binary search! An effificent way to search through 
 * an already sorted list of data.
 * Guaranteed time complexity of O(logn) search
 */

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

bool binarySearchRec(int *arr, int value, int low, int high);
void binarySearch(int *arr, int value, int size);

#endif
