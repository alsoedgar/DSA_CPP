#include <iostream>
#include <queue>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

//BFS
int treeSum(Node* root) {
    if (root == nullptr) return 0;

    std::queue<Node*> queue;
    queue.push(root);
    int sum = 0;

    while(!queue.empty()){
        Node* currentNode = queue.front();
        sum += (queue.front()->val);
        queue.pop();

        if (currentNode->left != nullptr) queue.push(currentNode->left);
        if (currentNode->right != nullptr) queue.push(currentNode->right);
    }
    return sum;
}


//DFS
int treeSumRec(Node *root){
    if (root == nullptr) return 0;
    return root->val + treeSumRec(root->left) + treeSumRec(root->right);
}

int main() {
    // 1. Manually build the tree described above here...
    Node* root = new Node(5);
    // (Add the rest of the nodes carefully!)
    root->left = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(1);

    // 2. Test your treeSum function...
    std::cout << "Total Sum: " << treeSum(root) << std::endl; // Expected: 26
    std::cout << "Total Sum: " << treeSumRec(root) << std::endl; //26

    return 0;
}