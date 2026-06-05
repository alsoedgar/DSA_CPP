#include <iostream>
#include <string>
#include <vector>
#include "bst.h"

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

bool insertNumber(treeNode** rootptr, int value){
    treeNode *root = *rootptr;

    if (root == nullptr){
        //tree empty
        (*rootptr) = createNode(value);
        return true; 
    }
    if (value == root->value){
        //do nothing, duplicate
        return false;
    }
    if(value < root->value){
        return insertNumber(&(root->left), value);
    }
    else{
        return insertNumber(&(root->right), value);
    }
}

//targeted searching, takes advantage of BST properties
//O(logn) search complexity 
bool findNumber(treeNode* root, int value){
    if (root == nullptr){
        return false;
    }
    if (root->value == value){
        return true;
    }
    if(value < root->value){
        return findNumber(root->left, value);
    }
    else{
        return findNumber(root->right, value);
    }
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

//recursive node deletion function
treeNode* deleteNode(treeNode* root, int value){
    //empty tree case
    if(root == nullptr){
        return nullptr;
    }

    //search through tree
    if(value < root->value){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->value){
        root->right = deleteNode(root->right, value);
    }
    //deletion
    else{
        //value has no child nodes
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        //value has one child nodes
        //left child
        else if(root->right == nullptr){
            treeNode* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        else if(root->left == nullptr){
            treeNode* temp = root->right;
            delete root;
            return temp;
        }

        //value has two child nodes
        else{
            //find inorder successor (smallest right tree node)
            treeNode* successor = root->right;
            while(successor->left != nullptr){
                successor = successor->left;
            }

            //overwrite root node value with successor value 
            root->value = successor->value;
            //delete duplicate value from successor
            root->right = deleteNode(root->right, successor->value);
        }
    }
    return root;
}

//pre-order traversal (good for copying trees)
void depthFirstTraversalIterative(treeNode* const root){
    std::vector<treeNode*> stack;

    if (root->value == -1 || root == nullptr) return;
    stack.push_back(root);

    while(!stack.empty()){
        treeNode* current = stack.back();
        cout << current->value << " ";
        stack.pop_back();
        
        if(current->right != nullptr){
            stack.push_back(current->right);
        }
        if(current->left != nullptr){
            stack.push_back(current->left);
        }
    }
}

//post-order, good for deleting trees!
void depthFirstTraversalRecursive(treeNode* root){
    if (root == nullptr || root->value == -1) return;
    
    depthFirstTraversalRecursive(root->left); //left
    depthFirstTraversalRecursive(root->right); //right

    cout << root->value << " "; //root
}

//O(n) time & space complexity (with good implementation of queue)
void breadthFirstSearchIterative(treeNode* root){
    if (root == nullptr) return;

    std::vector<treeNode*> queue;
    queue.push_back(root);

    while(!queue.empty()){
        treeNode* currentNode = queue.front();
        cout << queue.at(0)->value << " ";

        queue.erase(queue.begin());

        //check left independently
        if(currentNode->left!= nullptr){
            queue.push_back(currentNode->left);
        }
        //check right independently
        if (currentNode->right != nullptr){
            queue.push_back(currentNode->right);
        }

    }
}

