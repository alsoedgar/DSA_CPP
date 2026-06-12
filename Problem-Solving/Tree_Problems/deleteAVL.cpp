#include <iostream>
#include <algorithm>

struct TreeNode{
    int key;
    int height;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : key(key), height(0), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* root){
    if(root == nullptr) return -1;

    return root->height; //O(1) time complexity height lookup
}

int getBalanceFactor(TreeNode* root){
    if (root == nullptr) {return 0;}

    int maxLeft = getHeight(root->left);
    int maxRight = getHeight(root->right);

    return maxLeft - maxRight;
}

TreeNode* rotateRight(TreeNode* x){
    TreeNode* y = x->left; 
    TreeNode* temp = y->right;

    y->right = x;
    x->left = temp;


    //update heights again
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right)); //child first
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));; //then parent
    
    //return root back
    return y;
}

TreeNode* rotateLeft(TreeNode* a){
    TreeNode* b = a->right; 
    TreeNode* temp = b->left;

    b->left = a;
    a->right = temp;

    //update heights again
    a->height = 1 + std::max(getHeight(a->left), getHeight(a->right)); //child first
    b->height = 1 + std::max(getHeight(b->left), getHeight(b->right)); //then parent
    
    //return root back
    return b;
}

void inorderTravRec(TreeNode* root){
    if (root == nullptr) return;

    if (root->left != nullptr) inorderTravRec(root->left);
    std::cout << root->key << " ";
    if(root->right != nullptr) inorderTravRec(root->right);
}

TreeNode* insertNode(TreeNode* root, int key){
    
    //create tree if empty tree
    if (root == nullptr) {
        return new TreeNode(key);
    }

    //branch left or right based off of value 
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    else {
        return root; //duplicate node
    } 

    //update height && get balance factor
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1){   //left heavy rotations
        if (getBalanceFactor(root->left) < 0){
            root->left = rotateLeft(root->left); //LR rotation
        }
            root = rotateRight(root); //LL rotation
    }

    else if (balance < -1){  //Right-heavy rotations
        if(getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right); //RL rotation
        }
        root = rotateLeft(root); //RR rotation
    }

    return root;
}

TreeNode* deleteNode(TreeNode*& root, int key){
    if (root == nullptr) return root; //base case
    //traverse to find key
    if(key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key){
        root->right = deleteNode(root->right, key);
    }
    //deletion phase
    else{
        if(root->left == nullptr){
            TreeNode* temp = root->right;
            delete root;
            root = temp;
        } 
        else if(root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;        
            root = temp;
        }
        else{
            TreeNode* temp = root->right;
            while (temp->left != nullptr){
                temp = temp->left;
            }
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root; //if root only had 1 node and was deleted

        //update heights
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        //check balance factor
        int balanceFactor = getBalanceFactor(root);

        //rotations
        //right heavy
        if (balanceFactor < -1){ 
            if(getBalanceFactor(root->right) > 0){
                root->right = rotateRight(root->right);
            }
            root = rotateLeft(root);
        }
        //left heavy
        else if(balanceFactor > 1){
            if(getBalanceFactor(root->left) < 0){
                root->left = rotateLeft(root->left);
            }
            root = rotateRight(root);
        }
    return root;
}


void deleteTree(TreeNode*& root){
    if(root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}


int main(){

    TreeNode* root = nullptr;
    root = insertNode(root, 15);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 5);
    root = insertNode(root, 30);
    root = insertNode(root, 25);

    inorderTravRec(root);

    std::cout << "\n";

    deleteNode(root, 5);
    inorderTravRec(root);

    deleteTree(root);
    
}