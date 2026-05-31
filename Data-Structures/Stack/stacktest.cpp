#include <iostream>
#include "stack.h"

using namespace std;

int main(){
   
    Stack x;

    x.push(10);
    x.pop();
    if(x.peek() == -1){
        cout << "stack is empty\n";
    } 
    else{
        cout << x.peek();
    }
    
}