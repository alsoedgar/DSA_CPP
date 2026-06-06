#include <iostream>
#include "avl.h"

//g++ *.cpp -o main

int main(){
    Node* root = nullptr;
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 5);

    printTree(root);
    std::cout << std::endl;
    std::cout << getBalanceFactor(root);

}