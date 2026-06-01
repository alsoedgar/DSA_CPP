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

    printTree(root);

    bool temp = findNumber(root, 16);
    if(temp){
        cout << "16 was found\n";
     } else cout << "16 not in tree\n";

    temp = findNumber(root, 111);
    if(temp){
        cout << "111 was found\n";
     } else cout << "111 not in tree\n";


     deleteNode(root, 15);
     printTree(root);

}