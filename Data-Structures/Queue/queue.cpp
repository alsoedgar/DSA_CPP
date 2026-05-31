#include "queue.h"
#include <iostream>

using std::cout;

Queue::Queue() : front(-1), rear(-1){}

void Queue::enqueue(int data){
    if (isFull()){
        cout << "Queue is full!\n";
    }
    else{
        if (front == -1){
            front = 0;
        }
        a[++rear] = data;
        cout << data << " is enqueued\n"; 
    }
}

int Queue::dequeue(){
    int element;
    if(isEmpty()){
        cout << "Queue is empty!\n";
        return 0;
    }
    else{
        element = a[front];
        if(front >= rear){
            front = -1;
            rear = -1;
        }
        else{
        front++;
        }
        cout << element << " has been dequeued\n";
        return element;
    }
}

int Queue::peek(){
    if (front == -1){
        cout << "queue is empty";
        return -1;
    }
    return a[front];
}

bool Queue::isFull(){
    if (front == 0 && rear == MAX - 1){
        return true;
    }
    return false;
}

bool Queue::isEmpty(){
    return front == -1;
}