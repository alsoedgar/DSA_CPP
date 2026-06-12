#include <iostream>

//g++ tree_deletion.cpp -o main

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// WRITE YOUR SOLUTION HERE
// recursive solution
Node* deleteNode(Node* root, int target) {
    if (root == nullptr) return root;
    
    if (target < root->val) root->left = deleteNode(root->left, target);
    else if (target > root->val) root->right = deleteNode(root->right, target);
    else{
    //cases
    if (root->left == nullptr && root->right == nullptr){
        delete root;
        return nullptr;
    }
    else{
            if(root->left == nullptr && root->right != nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->left != nullptr && root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node* current = root->right;
                while (current->left != nullptr) {
                    current = current->left; 
            }
                root->val = current->val;
                root->right = deleteNode(root->right, root->val);
        }
    }
}
        return root;
}

// Pre-order print to verify your tree structure
void printTree(Node* root) {
    if (root == nullptr) return;
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    /*
                15
              /    \
             6      20
            / \     / \
           3   8   18  25
    */

    Node* root = new Node(15);
    root->left = new Node(6);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(18);
    root->right->right = new Node(25);

    // Test Case: Delete node 6 (Node with 1 child)
    root = deleteNode(root, 6);
    
    std::cout << "Pre-order traversal after deletion: ";
    printTree(root); 
    // Expected output: 15 8 3 20 18 25 (if 8 took 6's place and kept 3)
    
    return 0;
}