#ifndef __BINARYTREE_H_
#define __BINARYTREE_H_

#include "TreeNode.hpp"
#include <vector>
#include <fstream>
#include <sstream>

using std::string;


// Estrutura da BinaryTree
class BinaryTree {
private:
    TreeNode* ptrRoot = nullptr; // Ponteiro para a raiz da árvore
public:
    BinaryTree(); // Construtor da árvore
    ~BinaryTree(); // Destrutor da árvore

    // Funções de acesso e informações da árvore
    TreeNode* getRoot(); // Retorna um ponteiro para a raiz da árvore
    int getHeight(); // Retorna a altura da árvore
    int getSize(); // Retorna o número de nós na árvore
    bool isComplete(); // Verifica se a árvore é completa
    bool isPerfect(); // Verifica se a árvore é perfeita
    std::vector<int> convertToVector(); // Converte a árvore em um vetor

    // Funções para obter tamanho e altura da árvore
    int height();  // função para obter a altura da árvore
    int size();  // função para obter o tamanho da árvore

    // Novos métodos para auxiliar na remoção
    TreeNode* findMin(TreeNode* node);  // Este método retorna o nó com o menor valor na árvore
    TreeNode* remove(int iData, TreeNode* node);  // Este é o nosso método de remoção recursivo. Ele percorre a árvore e remove o nó com o valor fornecido

    // Funções auxiliares que operam diretamente em nós
    int height(TreeNode* node);  // função para obter a altura de um nó específico
    int size(TreeNode* node);  // função para obter o tamanho de um nó específico

    // Funções auxiliares para verificar se a árvore é completa e perfeita de um nó específico
    bool isComplete(TreeNode* node, int iIndex, int iNumNodes);  // função para verificar se a árvore a partir do nó é completa
    bool isPerfect(TreeNode* node, int iDepth, int iLevel = 0);  // função para verificar se a árvore a partir do nó é perfeita

    // Novos métodos para construção da árvore
    void buildFromTextFile(const string &filename); // Construir uma árvore a partir de um arquivo texto
    void buildFromUserInput(const std::vector<int> &userInput); // Construir uma árvore a partir de dados digitados pelo usuário

    // Funções principais
    void insert(int iData); // Insere um elemento na árvore
    bool remove(int iData); // Remove um elemento da árvore, retorna true se a remoção foi bem-sucedida
    bool search(int iData); // Procura um elemento na árvore, retorna true se o elemento estiver presente


    // Funções para impressão da árvore
    void displayBFS(TreeNode* ptrRoot); // Imprime a árvore em largura

};

#endif // __BINARYTREE_H_
