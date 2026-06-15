/*
 * Red-Black Tree! This is another variation of a self-balancing binary tree. It is a bit more flexible than an AVL tree, however
 * uses 4 strict rules to still guarantee O(logn) time complexity for all search, insert, and delete operations
 * This tree still uses O(n) space complexity depending on the amount of nodes it stores! 
 * This tree uses the colors red and black to ensure that, 1. every node is red or black, 2. the root & leaves (NIL) are black 
 * 3. each red node has a black child, 4.All paths from a node to its NIL descendants hav ethe same # of black nodes 
 */

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H 

enum Color{
    RED, BLACK
};

struct TreeNode{
    int key;
    Color color;
    
    TreeNode* left, *right, *parent;
    TreeNode(int key) : key(key), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

//printing tree
void printInOrder(TreeNode* root);

//RBT insertion
TreeNode* insert(TreeNode*& root, int key); //helper function
TreeNode* insertNode(TreeNode* root, TreeNode* newNode); //recursive insertion function

//follow RBT rules
TreeNode* fixInsertViolations(TreeNode* root, TreeNode* newNode); //follow RBT rules and recursively fix nodes w rotations and color changes

//rotations
TreeNode* rotateLeft(TreeNode* root);
TreeNode* rotateRight(TreeNode* root);

//deleting tree
void deleteTree(TreeNode*& root);

#endif