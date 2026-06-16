#include <iostream>
#include <vector>
#include "quick_sort.h"

int main(){
    std::vector<int> a = {23, 56, 2, 34 ,6, 856, 8, 756};

    quickSortRecursion(a, 0 , a.size()-1);

    for (int element : a){
        std::cout << element << " ";
    }
}