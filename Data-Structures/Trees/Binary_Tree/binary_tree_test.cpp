#include <iostream>
#include "binary_tree.h"

int main(){
    treeNode *n1 = createNode(10);
    treeNode *n2 = createNode(11);
    treeNode *n3 = createNode(12);
    treeNode *n4 = createNode(13);
    treeNode *n5 = createNode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printTree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}