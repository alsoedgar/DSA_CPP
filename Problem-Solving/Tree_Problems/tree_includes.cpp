#include <iostream>
#include <queue>
#include <stack>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// WRITE YOUR SOLUTION HERE

//blind searching 

//BFS 
bool treeIncludes(Node* root, int target) {
    if (root == nullptr) return false;

    std::queue<Node*> queue;
    queue.push(root);

    while(!queue.empty()){
        Node* currentNode = queue.front();
        if(currentNode->val == target) return true;
        queue.pop();

        if(currentNode->left != nullptr) queue.push(currentNode->left);
        if(currentNode->right != nullptr) queue.push(currentNode->right);
    }
    return false;
}

//DFS 
bool treeIncludesRec(Node* root, int target){
    if (root == nullptr) return false;
    if (root->val == target) return true;
    return treeIncludesRec(root->right, target) || treeIncludesRec(root->left, target);
}

int main() {
    // 1. Manually build the tree described above here...
    Node* root = new Node(12);
    // (Add the rest of the nodes)
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(9);
    root->left->right->left = new Node(7);
    root->right = new Node(18);
    root->right->right = new Node(25);
    root->right->right -> left = new Node(21);

    // 2. Test your treeIncludes function against the test cases...
    std::cout << treeIncludesRec(root, 9);
    std::cout << treeIncludesRec(root, 21);
    std::cout << treeIncludesRec(root, 12);
    std::cout << treeIncludesRec(root, 15);
    std::cout << treeIncludesRec(root, 0);
    
    
    return 0;
}