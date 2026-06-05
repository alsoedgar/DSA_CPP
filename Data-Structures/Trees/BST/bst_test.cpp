#include <iostream>
#include "bst.h"

using std::cout;

int main(){
    treeNode* root = nullptr;

    insertNumber(&root, 15);
    insertNumber(&root, 11);
    insertNumber(&root, 24);
    insertNumber(&root, 5);
    insertNumber(&root, 16);
    insertNumber(&root, 6);

    //            15
    //       11        24
    //     5    6    16
    //

    printTree(root);

    depthFirstTraversalIterative(root);
    cout << "\n";
    depthFirstTraversalRecursive(root);
    cout << '\n';
    breadthFirstSearchIterative(root);
    cout << 'n';
  
    