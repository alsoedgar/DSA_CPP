/*
 * AVL trees are an extension of binary trees! The main issue with BST's
 * are that, if you insert nodes in sorted order, the tree can turn into a linked list
 * This completely defeats the purpose of the efficient O(logn) time complexity for lookups 
 * SO- to solve this AVL's are trees that sort themselves, they track each nodes height variable
 * check if the height of one subtree is bigger than the other, and if so, it rotates the tree to fix
 * the order!
 * 
 * AVL trees have O(logn) for all 3 core functions, lookup, insertion, and delete!
 */

#ifndef AVL_H
#define AVL_H

struct Node{
    int val;
    int height;

    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr), height(0){}
    
};

    void printTree(Node* root);
    int getBalanceFactor(Node* root);
    int getHeight(Node* root);
    void updateHeight(Node* root);
    void insertNode(Node*& root, int val);
    void rotateLeft(Node*& root);
    void rotateRight(Node*& root);
    
#endif