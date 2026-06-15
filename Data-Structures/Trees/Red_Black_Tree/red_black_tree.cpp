#include "red_black_tree.h"
#include <iostream>

TreeNode* rotateLeft(TreeNode* x){
    TreeNode* originalParent = x->parent; //grab original parent to update links

    TreeNode* y = x->right;
    TreeNode* temp = y->left;

    y->left = x;
    x->right = temp;
    
    //update parent nodes
    if (temp!=nullptr) temp->parent = x;
    x->parent = y;
    y->parent = originalParent;

    //update original parent's childnode
    if(originalParent!= nullptr){
        if(x == originalParent->left){
            originalParent->left = y;
        }
        else{
            originalParent->right = y;
        }
    }

    return y;
}

TreeNode* rotateRight(TreeNode* x){
    TreeNode* originalParent = x->parent; //grab original parent to update links

    TreeNode* y = x->left;
    TreeNode* temp = y->right;

    y->right = x;
    x->left = temp;
    
    //update parent nodes
    if (temp!=nullptr) temp->parent = x;
    x->parent = y;
    y->parent = originalParent;

    //update original parent's childnode
    if(originalParent!= nullptr){
        if(x == originalParent->left){
            originalParent->left = y;
        }
        else{
            originalParent->right = y;
        }
    }

    return y;
}

//main wrapper function
TreeNode* insert(TreeNode*& root, int key){
    TreeNode* newNode = new TreeNode(key);

    //empty tree
    if (root == nullptr){
        root = newNode;
        root->color = BLACK; 
        return root;
    }

    //passes new node to BST insertion
    TreeNode* insertedResult = insertNode(root, newNode);

    if(insertedResult == nullptr){ //safely handle dupes
        delete newNode;
        return root; //return tree without fixing violations
    }

    root = insertedResult;
    root = fixInsertViolations(root, newNode);

    return root;
}

//bst recursive insertion 
TreeNode* insertNode(TreeNode* root, TreeNode* newNode){

    if (root == nullptr) return newNode; //empty tree 

    //BT search logic
    if (newNode->key < root->key){
        root->left = insertNode(root->left, newNode);
        root->left->parent = root;
    }
    else if(newNode->key > root->key){
        root->right = insertNode(root->right, newNode);
        root->right->parent = root;
    }
    else{
        return nullptr; //duplicate node
    }
    return root;
} 

TreeNode* fixInsertViolations(TreeNode* root, TreeNode* current){

    while(current != root && current->parent != nullptr && current->parent->color == RED){ //violation conditions (newnode is red and so is parent)
        TreeNode* parent = current->parent;
        TreeNode* grandparent = parent->parent;
        
        if (parent == grandparent->left){//if parent is on left side of grandparent
            TreeNode* uncle = grandparent->right;

            //case 2: new nodes uncle is red
                if (uncle != nullptr && uncle->color == RED){
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED; 
                    current = grandparent; //move up to find more violations
                }
            else{
            //case 3: new nodes uncle is black (triangle) --> transforms into case 4
                if(current == parent->right){
                    current = parent;  //update current to parent to rotate it
                    TreeNode* newSubRoot =  rotateLeft(current);
                    if (current == root) root = newSubRoot;

                    parent = current->parent;
                }
                
            //case 4: new nodes uncle is black (line)
                    parent->color = BLACK;
                    grandparent->color = RED;
                    TreeNode* newSubRoot = rotateRight(grandparent);
                    if (root == grandparent) root = newSubRoot;
            }
        }
        //if parent is on right side of grandparent (mirrored)
        else if (parent == grandparent->right){
            TreeNode* uncle = grandparent->left;

            //case 2: new nodes uncle is red
            if(uncle != nullptr && uncle->color == RED){
                uncle->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                current = grandparent;
            }
            else{
            //case 3: new nodes uncle is black (triangle)
                if(current == parent->left){
                    current = parent;
                    TreeNode* newSubRoot = rotateRight(current);
                    if(current == root) root = newSubRoot;

                    parent = current->parent;
                }

            //case 4: new nodes uncle is black (line)
                parent->color = BLACK;
                grandparent->color = RED;
                TreeNode* newSubRoot = rotateLeft(grandparent);
                if(root == grandparent) root = newSubRoot;

            }
        }
    }
        //case 1 exit
        root->color = BLACK;
        return root;
}

void printInOrder(TreeNode* root){
    if (root == nullptr) return;

    printInOrder(root->left);
    std::cout << root->key << (root->color == RED ?  "(R) " : "(B) ");
    printInOrder(root->right);
}

void deleteTree(TreeNode*& root){
    if (root == nullptr)return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}