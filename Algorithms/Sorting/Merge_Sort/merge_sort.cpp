#include "merge_sort.h"
#include <vector>

void mergeSort(std::vector<int>& vec){
    if(vec.size() <= 1) return;

    int mid = vec.size()/2;
    std::vector<int> leftArr(vec.begin(), vec.begin() + mid);
    std::vector<int> rightArr(vec.begin() + mid, vec.end());

    mergeSort(leftArr);
    mergeSort(rightArr);
    merge(leftArr, rightArr, vec);
}

void merge(std::vector<int>& leftArr, std::vector<int>& rightArr, std::vector<int>& vec){

    int leftSize = leftArr.size();
    int rightSize = rightArr.size();
    int i = 0, l = 0, r = 0; //indices

    //conditions for merging
    while(l < leftSize && r < rightSize){ //while elements are still in left array and elements in right array
        if(leftArr.at(l) < rightArr.at(r)){
            vec.at(i) = leftArr.at(l);
            i++; //increment original array index
            l++; //we added left element, so increment left index
        }
        else{
            vec.at(i) = rightArr.at(r);
            i++; //increment original array index
            r++; //we added right element, so increment right index
        }
    }
    //case if right side is empty but left side still has elements
        while(l < leftSize){
            vec.at(i) = leftArr.at(l);
            i++;
            l++;
        }
        //case if left side is empty but right side still has elements
        while(r < rightSize){
            vec.at(i) = rightArr.at(r);
            i++;
            r++;
    }
}