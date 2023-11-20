#include <iostream>

struct BTNode {
    int data;
    BTNode* left;
    BTNode* right;

    BTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBST(BTNode* bt) {
    if (bt == nullptr)
        return true;
    else if (bt->left != nullptr && bt->data <= bt->left->data)
        return false;
    else if (bt->right != nullptr && bt->data >= bt->right->data)
        return false;
    return isBST(bt->left) && isBST(bt->right);
}

int main() {
    // Example usage:
    // Construct a sample BST:
    //        2
    //       / \
    //      1   3
    BTNode* root = new BTNode(2);
    root->left = new BTNode(1);
    root->right = new BTNode(3);

    if (isBST(root)) {
        std::cout << "The binary tree is a BST." << std::endl;
    } else {
        std::cout << "The binary tree is not a BST." << std::endl;
    }

    return 0;
}
