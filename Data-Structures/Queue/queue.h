//array implementation of a queue
//queue is a FIFO (first-in-first-out operation)
//contains operations such as enqueue, dequeue, peek, isFull, isEmpty
//O(1) constant time operations for operations, except dequeueing is O(N) for shifting elements
//Unless list is circular and you shift 'front' up each time (then O(1) for all operations) 

#ifndef QUEUE_H
#define QUEUE_H
#define MAX 1000 //max size of queue

class Queue{
    private:
    int front, rear, a[MAX];

    public:
    Queue();
    void enqueue(int data);
    int dequeue();
    int peek();
    bool isFull();
    bool isEmpty();
};

#endif