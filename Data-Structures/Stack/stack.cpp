#include <iostream>
#include "stack.h"

using std::cout;


bool Stack::push(int data){
    if (top >= (MAX - 1)){
        cout << "Stack overflow\n";
        return false;
    }
    else{
        a[++top] = data;
        cout << data << " pushed into stack\n";
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout << "Stack underflow\n";
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if (top < 0){
        cout << "Stack is empty, nothing to peek\n";
        return -1;
    }
    return a[top];
}

bool Stack::isEmpty(){
    return top == -1;
}