#include "BinaryTree.h"

BinaryTree::BinaryTree() : ptrRoot(nullptr) {}

void BinaryTree::insert(int iData) {
    ptrRoot = insert(iData, ptrRoot);
}

TreeNode* BinaryTree::insert(int iData, TreeNode* node) {
    if (node == nullptr) {
        node = new TreeNode;
        node->iData = iData;
        node->ptrLeft = nullptr;
        node->ptrRight = nullptr;
    } else if (iData < node->iData) {
        node->ptrLeft = insert(iData, node->ptrLeft);
    } else if (iData > node->iData) {
        node->ptrRight = insert(iData, node->ptrRight);
    }
    return node;
}