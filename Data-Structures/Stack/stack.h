//stack implementation using a fixed array!
//stack is a LIFO operation (last-in-first-out) 
//only worries about the top of the stack and inclues operations push, pop, peek, and isEmpty
//O(1) constant time for operations with a fixed array

#ifndef STACK_H
#define STACK_H

#define MAX 10 //predefined fixed size of array

class Stack{
    private:
    int top;
    int a[MAX];
    
    public: 
    Stack(){top = -1;}
    bool push(int data);
    int pop();
    int peek();
    bool isEmpty();
};

#endif