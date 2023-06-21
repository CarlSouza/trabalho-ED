#include "BinaryTree.h"

BinaryTree::BinaryTree() : ptrRoot(nullptr) {}// construtor.

void BinaryTree::insert(int iData) {
    if (ptrRoot == nullptr) {
        ptrRoot = new TreeNode;
        ptrRoot->iData = iData;
        ptrRoot->ptrLeft = nullptr;
        ptrRoot->ptrRight = nullptr;
    } else {
        TreeNode* currentNode = ptrRoot;
        TreeNode* parentNode;
        while (true) {
            parentNode = currentNode;
            if (iData < currentNode->iData) {
                currentNode = currentNode->ptrLeft;
                if (currentNode == nullptr) {
                    parentNode->ptrLeft = new TreeNode;
                    parentNode->ptrLeft->iData = iData;
                    return;
                }
            } else {
                currentNode = currentNode->ptrRight;
                if (currentNode == nullptr) {
                    parentNode->ptrRight = new TreeNode;
                    parentNode->ptrRight->iData = iData;
                    return;
                }
            }
        }
    }
}

bool BinaryTree::remove(int iData) {
    // Implementação futura
    return false; // Modificar de acordo com a implementação
}

bool BinaryTree::search(int iData) {
    // Implementação futura
    return false; // Modificar de acordo com a implementação
}



