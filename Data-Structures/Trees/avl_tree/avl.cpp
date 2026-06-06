#include "avl.h"
#include <iostream>

void printTree(Node* root){
    if(root == nullptr) return;

    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
    return;
}

int getHeight(Node* root){
    if (root == nullptr) return -1;
    return root->height;
}

int getBalanceFactor(Node* root){
    if (root == nullptr) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(Node* root){
    
    if(root != nullptr){
        int maxLeft = getHeight(root->left);
        int maxRight = getHeight(root->right);

        root->height = 1 + (maxLeft > maxRight ? maxLeft : maxRight);
    }

}

void rotateLeft(Node*& y){
    Node* x = y->right;
    Node* temp = x->left;

    x->left = y;
    y->right = temp;

    //update child height first
    updateHeight(y);
    updateHeight(x);

    y = x;
}

void rotateRight(Node*& x){
    Node* y = x->left;
    Node* temp = y->right;

    y->right = x;
    x->left = temp;

    //update child height first
    updateHeight(x);
    updateHeight(y);

    x = y;
}

void insertNode(Node*& root, int val){
    if (root == nullptr){
        root = new Node(val);
        return;
    }

    if (val < root->val){
        insertNode(root->left, val);
    }
    else if(val > root->val){
        insertNode(root->right, val);
    } 
    else{
        return; //duplicate value
    }
    
    updateHeight(root);

    int balance = getBalanceFactor(root);

    //rotations
    if(balance > 1){ //left heavy
        if (getBalanceFactor(root->left) < 0){ //left-right case
            rotateLeft(root->left);
        }
        //left-left case or after left-right
        rotateRight(root);
    }
    else if(balance < -1){ //right heavy
        if(getBalanceFactor(root->right) > 0){ //right-left case
            rotateRight(root->right);
        }
        //right-right case or after right-left
        rotateLeft(root);
    }

}