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

bool BinaryTree::remove(int iData) {
    // Seu código de remoção aqui

    // Se a remoção for bem sucedida, retorne true
    // Caso contrário, retorne false
    return true; // Ou false, dependendo do resultado
}
