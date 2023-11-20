#include <iostream>

#include "BinaryTree.h"

using namespace std;

int main() {
    BTNode* root;
    BTNode *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8;

    // Code to create binary tree and test traversals (Lab #3, Question 3)

    node1 = createBTNode(30);
    node2 = createBTNode(10);
    node3 = createBTNode(50);
    node4 = createBTNode(25);
    node5 = createBTNode(40);
    node6 = createBTNode(90);
    node7 = createBTNode(35);
    node8 = createBTNode(70);

    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node3->left = node5;
    node3->right = node6;
    node5->left = node7;
    node6->left = node8;

    root = node1;

    cout << "Preorder traversal: ";
    preOrder(root);
    cout << endl << endl;

    cout << "Inorder traversal: ";
    inOrder(root);
    cout << endl << endl;

    cout << "Postorder traversal: ";
    postOrder(root);
    cout << endl << endl;

    // Write code to test functions from Lab #4, Question 1
    cout << "Moment: ";
    cout << moment(root);
    cout << endl << endl;

    cout << "Num one child: ";
    cout << numOneChild(root);
    cout << endl << endl;

    cout << "Num Terminal: ";
    cout << numTerminal(root);
    cout << endl << endl;

    cout << "Maximum: ";
    cout << maximum(root);
    cout << endl << endl;

    // Write code to test non-recursive inorder traversal (Lab #4, Question
    // 3(b))
    cout << "Inorder traversal: ";
    inOrderNonRecursive(root);
    cout << endl << endl;

    // Write code to test non-recursive preorder traversal (Lab #4, Question
    // 3(d))
    cout << "PreOrder traversal: ";
    preOrderNonRecursive(root);
    cout << endl << endl;

    cout << "PostOrder traversal: ";
    postOrderNonRecursive(root);
    cout << endl << endl;

    cout << "\n3c To switch from an inorder to a preorder traversal, you would "
            "move the output step before pushing the "
            "node onto the stack.\n";

    return 0;
}
