#include <iostream>
#include <string>
#include "binary_tree.h"

using std::cout;

treeNode* createNode(int value){
    treeNode *result = new treeNode();
    if (result != nullptr){
        result->left = nullptr;
        result->right = nullptr;
        result->value = value;
    }
    return result;
}

void printTabs(int numtabs){
    for (int i = 0; i < numtabs; i++){
        cout << "\t";
    }
}

void printTree(treeNode *root){
    printTreeRec(root, 0);
}

void printTreeRec(treeNode* root, int level){
    if(root == nullptr){
        printTabs(level);
        cout << "---<empty>---\n";
        return;
    }

    printTabs(level);
    cout << "value = " << root->value << "\n";
    printTabs(level);
    cout << "left\n";

    printTreeRec(root->left, level+1);
    printTabs(level);
    cout << "right\n";
    
    printTreeRec(root->right, level+1);

    printTabs(level);
    cout << "Done\n";
}