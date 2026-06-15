#include <iostream>
#include <string>
#include "red_black_tree.h"

int main(){
    TreeNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 25);

    printInOrder(root); //inorder printing (should print in non-decreasing order and display colors of nodes)
    std::cout << '\n';
    deleteTree(root);

}