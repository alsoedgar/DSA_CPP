//Bubble sort, a sorting algorithm that compares every number's neighbor values to itself and makes a swap based on comparison
//Uses a double for loop to iterate through the list and guarantee it's sorted
//because it uses a double loop it is an O(n^2) algorithm, however if you implement a boolean check flag the BEST case can becom O(n) for sorted lists (still O(n^2) average)
//Space complexity is O(1) because it sorts in place (no new copies)

#include <iostream>

void swap (int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a[] = {4, 7, 2, 8, 2, 6, 9, 1};
    int size = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (a[j+1] < a[j]){
                swap(a[j+1], a[j]);
            }
        }
    }

    for (int element : a){
        std::cout << element << " ";
    }

}

//optimized O(n) best case solution
/*

    for (int i = 0; i < size; i++){
    bool swapped = false;

            for (int j = 0; j < size - i - 1; j++){
                if (a[j+1] < a[j]){
                    swap(a[j+1], a[j]);
                    swapped = true;
                }
            }
                if(!swapped) break;
        }

*/