#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <vector>

// Estrutura da BinaryTree
struct BinaryTree {
    TreeNode* ptrRoot; // Ponteiro para a raiz da árvore

    BinaryTree(); // Construtor da árvore
    ~BinaryTree(); // Destrutor da árvore

    // Funções principais
    void insert(int iData); // Insere um elemento na árvore
    bool remove(int iData); // Remove um elemento da árvore, retorna true se a remoção foi bem-sucedida
    bool search(int iData); // Procura um elemento na árvore, retorna true se o elemento estiver presente

    // Funções de acesso e informações da árvore
    TreeNode* getRoot(); // Retorna um ponteiro para a raiz da árvore
    int getHeight(); // Retorna a altura da árvore
    int getSize(); // Retorna o número de nós na árvore
    bool isComplete(); // Verifica se a árvore é completa
    bool isPerfect(); // Verifica se a árvore é perfeita
    std::vector<int> convertToVector(); // Converte a árvore em um vetor
};

#endif  // BINARYTREE_H
