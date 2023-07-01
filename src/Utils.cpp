#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "../headers/Utils.hpp"
#include "../headers/LinkedList.hpp"
#include "../headers/TreeNode.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

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
//funções para representar a parte gráfica por meio de Símbolos ASCII.
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
    // Criamos um head para a lista duplamente encadeada
    struct ListNode* head = nullptr;

    // Adicionamos os nodes na arvore na lista
    treeToList(root, &head);

    // Imprimimos a lista ainda nao ordenada
    // printList(head);
    // cout << endl;

    while (true) {
        printSortOptions();
        cout << "Selecione uma opcao digitando um numero de 1 a 13:  ";
        int iTypeSort;
        cin >> iTypeSort;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, insira um numero entre 1 e 15!" <<endl;
            continue;
        }
    

        auto start = std::chrono::high_resolution_clock::now(); //insere a contagem

        // Escolhe a forma de ordenacao
        switch(iTypeSort)
        {
            case 1:
                bubbleSort(&head,false);
                printList(head);
                break;
            case 2:
                selectionSort(&head,false);
                printList(head);
                break;
            case 3:
                insertionSort(&head,false);
                printList(head);
                break;
            case 4:
                shellSort(&head,false);
                printList(head);
                break;
            case 5:
                return;
            default:
                cout << "Opção inválida." <<endl;
                break;
        }

        auto end = high_resolution_clock::now();
        auto elapsed = duration_cast<microseconds>(end - start);
        cout << "O tempo gasto na operação foi: "<< elapsed.count() << " microsegundos"<<endl;
    };
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
