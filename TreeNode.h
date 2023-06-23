#ifndef TREE_NODE_H
#define TREE_NODE_H

// Definindo um nó da árvore
struct TreeNode {
    
    int iData;  // valor do nó
    TreeNode* ptrLeft;  // ponteiro para o nó à esquerda
    TreeNode* ptrRight; // ponteiro para o nó à direita
    
    // Construtor
    TreeNode() : ptrLeft(nullptr), ptrRight(nullptr), iData(0) {}
};

#endif // TREE_NODE_H