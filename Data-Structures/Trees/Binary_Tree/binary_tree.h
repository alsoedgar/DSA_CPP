/* 
 *  Binary Tree! Hierarchical, non-linear data structure where each parent node has
 *  at most 2 children. This is a basic implementation of it for conceptual learning!
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct treeNode{
    int value;
    treeNode *left;
    treeNode *right;

    treeNode() : value(-1), left(nullptr), right(nullptr){}
};

treeNode* createNode(int value);
void printTreeRec(treeNode* root, int level);
void printTree(treeNode* root);

#endif