#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "../headers/Utils.h"
#include "../headers/LinkedList.h"
#include "../headers/TreeNode.h"
// #include "../headers/BubbleSort.hpp"
// #include "../headers/InsertionSort.hpp"
// #include "../headers/SelectionSort.hpp"
// #include "../headers/ShellSort.hpp"

using std::cout;
using std::cin;
using std::endl;

void printSortOptions() {
    cout << "\n===========================================================================" << endl;
    cout << "|                          Converter em lista                          |" << endl;
    cout << "===========================================================================" << endl;
    
    cout << "\n==> Escolha o algoritmo:\n" << endl;
    cout << "1.  Bubble Sort" << endl;
    cout << "2.  Selection Sort" << endl; 
    cout << "3.  Insertion Sort" << endl;
    cout << "4.  Shell Sort" << endl;
    cout << "5.  Voltar ao menu principal" << endl;
    
    cout << "\n===========================================================================" << endl;                
}

// Função para encontrar o valor máximo no vetor
int find_max(const std::vector<int>& vec) {
    int max_value = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max_value) {
            max_value = vec[i];
        }
    }
    return max_value;
}

// Função para imprimir o vetor como barras de '#'
void print_bars(const std::vector<int>& vec) {
    int max_value = find_max(vec);
    for (int i = max_value; i > 0; i--) {
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] >= i) {
                std::cout << "# ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "\n";
    }

    for (int j = 0; j < vec.size(); j++) { // imprime os valores numéricos abaixo de cada barra
        std::cout << vec[j] << " ";
    }

    std::cout << "\n------------------\n"; // separador para cada passo da ordenação

    std::this_thread::sleep_for(std::chrono::seconds(1)); // pausa a execução por 1 segundos
    std::system("clear"); // limpa a tela
}
// Funcao para percorrer a arvore de forma iterativa, adicionando os elementos a uma lista.
void treeToList(struct TreeNode* root, struct ListNode** head)
{
    // Arvore vazia
    if (root == nullptr)
        return;
    
    // Insere o node atual na lista
    insertListNode(head, root->iData);

    // Percorre a sub-arvore da esquerda
    treeToList(root->ptrLeft, head);

    // Percorre a sub-arvore da direita
    treeToList(root->ptrRight, head);

    return;
};

void sort(struct TreeNode* root)
{
    printSortOptions();
    // Criamos um head para a lista duplamente encadeada
    struct ListNode* head = nullptr;

    // Adicionamos os nodes na arvore na lista
    treeToList(root, &head);

    // Imprimimos a lista ainda nao ordenada
    // printList(head);
    // cout << endl;

    int iTypeSort;
    cin >> iTypeSort;
    // Escolhe a forma de ordenacao
    switch(iTypeSort)
    {
        case 1:
            bubbleSort(&head,false);
            printList(head);
            sort(root);
            break;
        case 2:
            selectionSort(&head,false);
            printList(head);
            sort(root);
            break;
        case 3:
            insertionSort(&head,false);
            printList(head);
            sort(root);
            break;
        case 4:
            shellSort(&head,false);
            printList(head);
            sort(root);
            break;
        case 5:
            break;
        default:
            break;
    }

    return;
};

void showSort(struct TreeNode* root)
{
    printSortOptions();
    // Criamos um head para a lista duplamente encadeada
    struct ListNode* head = nullptr;

    // Adicionamos os nodes na arvore na lista
    treeToList(root, &head);

    // Imprimimos a lista ainda nao ordenada
    // printList(head);
    // cout << endl;

    int iTypeSort;
    cin >> iTypeSort;
    // Escolhe a forma de ordenacao
    switch(iTypeSort)
    {
        case 1:
            bubbleSort(&head,true);
            showSort(root);
            break;
        case 2:
            selectionSort(&head,true);
            showSort(root);
            break;
        case 3:
            insertionSort(&head,true);
            showSort(root);
            break;
        case 4:
            shellSort(&head,true);
            showSort(root);
            break;
        case 5:
            break;
        default:
            break;
    }

    return;
};