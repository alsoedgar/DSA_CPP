/*
 * Linear search! A search algorithm used to search unsorted items!
 * Good for searching unsorted items and doesn't require creating new arrays
 * O(n) time complexity average case and O(1) for best case (first item checked)
 * O(1) space complexity, iterative!
 * Also i'm only using just one .cpp file for this one out of simplicity sake :P
 */
#include <iostream>
using std::cout;

int main(){
    int arr[] = {67, 420, 47, 34, 1001, 12, 38, 555, 627}; //unsorted array
    bool inArray = false;
    int value = 1001; //first value searching for (in list)

    //searching through array one by one to check if item is exists in array
    for (int i : arr){
        if(value == i){
            inArray = true;
            break;
        }
    }
    if(inArray){
        cout << value << " is in the array\n";
    } else cout << value << " not in array :(\n";

    value = 1234;
    inArray = false; //reset variable

    for (int i : arr){
        if(value == i){
            inArray = true;
            break;
        }
    }
    if(inArray){
        cout << value << " is in the array\n";
    } else cout << value << " not in array :(\n";

    return 0;
    
}

