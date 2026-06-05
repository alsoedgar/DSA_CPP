#include <iostream>
#include <algorithm>
#include <climits>

//run g++ max_root_to_leaf_path_sum.cpp -o main (long name)

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// WRITE YOUR SOLUTION HEREW
int maxPathSum(Node* root) {
    if (root == nullptr) return -INT_MAX;
    if (root->left == nullptr && root->right == nullptr) return root->val;

    int maxChildPathSum = std::max(maxPathSum(root->left), maxPathSum(root->right));

    return root->val + maxChildPathSum;
}

int main() {

/*        5
        /   \
       11    3      //tree
      /  \    \
     4    2    1 
*/
    
    Node* root = new Node(5);
    root->left = new Node(11);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    root->right->right = new Node(1);

    std::cout << "Max Path Sum: " << maxPathSum(root) << std::endl; // Expected: 20
    return 0;
}