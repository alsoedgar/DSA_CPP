#include <iostream>
#include "binary_search.h"

using std::cout;

int main(){
 
    int arr[] = {5, 8, 12, 56, 207, 302, 1001}; //sorted test array
    size_t size = sizeof(arr)/sizeof(arr[0]); 

    binarySearch(arr, 12, size);
    binarySearch(arr, 5, size);
    binarySearch(arr, 67, size);
    binarySearch(arr, 1001, size);

    return 0;
}