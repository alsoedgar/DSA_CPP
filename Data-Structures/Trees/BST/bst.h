/* 
 *  Binary Search Tree! Extension of a binary tree (using similar functions and 
 *  code) however a binary search tree is useful for maintaining sorted lists efficiently.
 *  Left nodes are smaller while right nodes are larger
 *  In a balanced tree, average O(logn) times for search, deletion, and insertion
 *  However, in a skewed/degenerate tree, it basically turns into a linked list having worst case O(N)
 *  times for search, deletion, and inserting
 */

#ifndef BST_H
#define BST_H

struct treeNode{
    int value;
    treeNode *left;
    treeNode *right;

    treeNode() : value(-1), left(nullptr), right(nullptr){}
};

treeNode* createNode(int value);
bool insertNumber(treeNode** rootptr, int value);
bool findNumber(treeNode* root, int value);
void printTreeRec(treeNode* root, int level);
void printTree(treeNode* root);
treeNode* deleteNode(treeNode* root, int value);

//time complexity is O(n), n = # of nodes
//space complexity is O(n)
void depthFirstTraversalIterative(treeNode* const root);
void depthFirstTraversalRecursive(treeNode* root);
void breadthFirstSearchIterative(treeNode* const root);


#endif