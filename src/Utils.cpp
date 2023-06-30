#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "../headers/Utils.hpp"
#include "../headers/LinkedList.hpp"
#include "../headers/TreeNode.hpp"
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

int find_max(struct ListNode* head) {
    int max_value = head->iData;
    struct ListNode* current = head->ptrNext;
    while (current != nullptr) {
        if (current->iData > max_value) {
            max_value = current->iData;
        }
        current = current->ptrNext;
    }
    return max_value;
} 
    
// Função para imprimir o vetor como barras de '#'
// void print_bars(struct ListNode* head) {
//     int max_value = find_max(head);
//     struct ListNode* current = head;
//     while (current != nullptr) {
//         int value = current->iData;
//         for (int i = 0; i < value; i++) {
//             std::cout << "# ";
//         }
//         std::cout << "\n";
//         current = current->ptrNext;
//     }
//     std::cout << "------------------\n";
// } 

void print_bars(struct ListNode* head) {
    int max_value = find_max(head);
    struct ListNode* current = head;

    while (max_value > 0) {
        while (current != nullptr) {
            if (current->iData >= max_value) {
                std::cout << "# ";
            } else {
                std::cout << "  ";
            }
            current = current->ptrNext;
        }
        std::cout << "\n";
        current = head;
        max_value--;
    }

    current = head;
    while (current != nullptr) {
        std::cout << current->iData << " ";
        current = current->ptrNext;
    }

    std::cout << "\n------------------\n"; // separador para cada passo da ordenação

    std::this_thread::sleep_for(std::chrono::seconds(1)); // pausa a execução por 1 segundo
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