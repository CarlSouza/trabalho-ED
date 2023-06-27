#ifndef __TREE_NODE_H_
#define __TREE_NODE_H_

// Definindo um nó da árvore
struct TreeNode {
    
    int iData;  // valor do nó
    TreeNode* ptrLeft;  // ponteiro para o nó à esquerda
    TreeNode* ptrRight; // ponteiro para o nó à direita
    
    // Construtor
    TreeNode() : ptrLeft(nullptr), ptrRight(nullptr), iData(0) {}
};

#endif // __TREE_NODE_H_