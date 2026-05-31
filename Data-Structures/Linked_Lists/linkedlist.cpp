#include "linkedlist.h"

#include <iostream>
using std::cout;

linkedList::~linkedList(){
    Node* temp;
    Node* current = head;

    while(current != nullptr){
        temp = current;
        current = current->pNext;
        delete temp;
    }
}    

void linkedList::appendNode(int data){
    Node* newNode = new Node(data);

    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->pNext!=nullptr){
            temp = temp->pNext;
        }
        temp->pNext = newNode;
    }
}

void linkedList::prependNode(int data){
    Node* newNode = new Node(data);
    newNode->pNext = head;
    head = newNode; 
}

void linkedList::deleteNode(int data){

    //empty list case
    if(head == nullptr){
        cout << "list is empty\n";
        return;
    }

    //head is the node you want to delete case
    if (head->data == data){
        cout << "deleted node containing " << data << " value\n";
        Node* toDelete = head;
        head = head->pNext;
        delete toDelete;
        return;
    }

    Node* temp = head;

    while(temp->pNext!=nullptr){
        if(temp->pNext->data == data){
            cout << "deleted node containing " << data << " value\n";
            
            Node* toDelete = temp->pNext;
            temp->pNext = temp->pNext->pNext;
            delete toDelete;
            return;
        }
        temp = temp->pNext;
    }
    cout << data << "was not in the list\n";
}

void linkedList::printList(){
    Node* temp = head; 
    int count = 0; 

    if(head == nullptr){
        cout << "list is empty!\n";
        return;
    }

    while(temp!=nullptr){
        cout << "Node #" << count << " | Data: " << temp->data << std::endl;
        count++;
        temp = temp->pNext;
    }
}