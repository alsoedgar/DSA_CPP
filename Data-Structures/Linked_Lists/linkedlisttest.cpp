#include <iostream>
#include "linkedlist.h"

using namespace std;

int main(){
    linkedList newList;
    linkedList newerList;
    
    newList.appendNode(10);
    newList.appendNode(15);
    newList.prependNode(6);
    newList.printList();
    newList.deleteNode(6);
    newList.printList();
    newerList.printList();

    return 0;
}