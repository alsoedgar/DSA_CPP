#include <iostream>
#include <queue>    
#include <climits>
#include <algorithm>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// WRITE YOUR SOLUTION HERE
int treeMin(Node* root) {
    if (root == nullptr) return 0;

    std::queue<Node*> queue;
    queue.push(root);
    int min = root->val;

    while(!queue.empty()){
        Node* current = queue.front();
        if (current->val < min) min = current->val;
        queue.pop();

        if(current->left != nullptr) queue.push(current->left);
        if(current->right != nullptr) queue.push(current->right);
    }
    return min;
}

int treeMinRec(Node* root){
    if (root == nullptr) return INT_MAX;
    int leftMin = treeMinRec(root->left);
    int rightMin = treeMinRec(root->right); 
    return std::min({root->val, leftMin, rightMin});
}

int main() {
    /* Manually building this tree:
              15
            /    \
           6      20
          / \     /
         8  -2   11
    */
    Node* root = new Node(15);
    root->left = new Node(6);
    root->right = new Node(20);
    
    root->left->left = new Node(8);
    root->left->right = new Node(-2);
    
    root->right->left = new Node(11);

    // Test your treeMin function
    std::cout << "Minimum Value: " << treeMinRec(root) << std::endl; // Expected: -2
    
    return 0;
}