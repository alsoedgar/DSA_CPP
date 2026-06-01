#include "binary_search.h"
#include <iostream>
using std::cout;

bool binarySearchRec(int *arr, int value, int low, int high){
    if (low > high){
        return false;
    }
    
    int mid = low + (high - low) / 2;

    if (value == arr[mid]){
        return true;
    }
    else if(value < arr[mid]){
        return binarySearchRec(arr, value, low, (mid - 1));
    }
    else{
        return binarySearchRec(arr, value, (mid + 1), high);
    }

    return false;
}

void binarySearch(int *arr, int value, int size){

    bool answer = binarySearchRec(arr, value, 0, static_cast<int>(size)-1);
    if (answer){
        cout << value << " is in array!\n";
    }
    else cout << value << " not in array\n";
}