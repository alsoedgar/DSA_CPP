#include <iostream>
#include "queue.h"

using namespace std;

int main(){
   
    Queue y;

    y.enqueue(10);
    y.enqueue(20);
    y.enqueue(30);
    y.dequeue();
    if(y.peek() == -1){
        cout << "queue is empty\n";
    } 
    else{
        cout << y.peek();
    }
}