#include <iostream>
#include <vector>
#include "merge_sort.h"


int main(){
    std::vector<int> vec = {324, 756, 1, 4, 67, 420};

    mergeSort(vec);

    for (int element : vec){
        std::cout << element << " ";
    }
}