//data structure used to store data in non-contigous memory locations, flexible size
//O(1) time complexity for insertion and deletion at the beginning (unless doubly linked list), and O(N) to traverse/print list
//common functions for a linked list are appending nodes, prepending nodes, printing all nodes, and deleting nodes

#ifndef LINKED_LIST
#define LINKED_LIST

struct Node{
    int data;
    Node *pNext;

    Node() : pNext(nullptr),  data(-1){};

    Node(int data){
        this->data = data;
        this->pNext = nullptr;
    }
};

class linkedList{
    private:
    Node *head;

    public:
    ~linkedList();
    linkedList() : head(nullptr){}
    void appendNode(int data);
    void prependNode(int data);
    void deleteNode(int data);
    void printList(); //read list only and print it
};

#endif