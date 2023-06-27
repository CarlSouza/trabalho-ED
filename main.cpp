#include <iostream>
#include <chrono> 
#include <algorithm>
#include "BinaryTree.h"

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

void print_menu() {
    cout << "\n===========================================================================" <<endl;
    cout << "|                          Explorador de Árvores                          |" <<endl;
    cout << "===========================================================================" <<endl;
    
    cout << "\n==> Menu de funcoes:\n" << endl;
    cout << "1.  Construir uma árvore binária a partir de um arquivo texto" <<endl;
    cout << "2.  Construir uma árvore binária a partir de dados digitados pelo usuário" <<endl;
    cout << "3.  Informar a altura da árvore" <<endl;
    cout << "4.  Informar o tamanho da árvore" <<endl;
    cout << "5.  Inserir um elemento fornecido pelo usuário" <<endl;
    cout << "6.  Remover um elemento fornecido pelo usuário" <<endl;
    cout << "7.  Buscar um elemento fornecido pelo usuário" <<endl;
    cout << "8.  Informar se a árvore é completa" <<endl;
    cout << "9.  Informar se a árvore é perfeita" <<endl;
    cout << "10. Exibir a árvore utilizando BFS" <<endl;
    cout << "11. Converter a árvore em uma lista e ordenar com Bubble Sort" <<endl;
    cout << "12. Converter a árvore em uma lista e ordenar com Selection Sort" <<endl;
    cout << "13. Converter a árvore em uma lista e ordenar com Insertion Sort" <<endl;
    cout << "14. Converter a árvore em uma lista e ordenar com Shell Sort" <<endl;
    cout << "15. Sair"<<endl;
    
    cout << "\n===========================================================================" <<endl;                
}

int main() {
    BinaryTree tree;
    while (true) {
        print_menu();
        cout << "Selecione uma opcao digitando um numero de 1 a 15:  ";
        int iOption;
        cin >> iOption;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, insira um numero entre 1 e 15!" <<endl;
            continue;
        }

        auto start = std::chrono::high_resolution_clock::now(); //insere a contagem

        switch (iOption) {
            case 1:
            {
                std::string filename;
                cout << "Digite o nome do arquivo: ";
                cin >> filename;
                tree.buildFromTextFile(filename);
                break;
            }
            case 2:
            {
                std::vector<int> userInput;
                int value;
                cout << "Digite os valores para construir a árvore (digite -1 para finalizar): ";
                while (cin >> value && value != -1) {
                    userInput.push_back(value);
                }
                tree.buildFromUserInput(userInput);
                break;
            }
                break;
            case 3:
                cout << "A altura da árvore é: " << tree.getHeight() << endl;
                break;
            case 4:
                cout << "O tamanho da árvore é: " << tree.getSize() << endl;
                break;
            case 5:    
            {
                int iDataToInsert;
                cout << "Digite o valor para inserir na árvore: ";
                cin >> iDataToInsert;
                tree.insert(iDataToInsert);
                break;
            }
            case 6:
            {
                int iDataToRemove;
                cout << "Digite o valor para remover da árvore: ";
                cin >> iDataToRemove;
                tree.remove(iDataToRemove);
                break;
            }
            case 7:
            {
                int iDataToSearch;
                cout << "Digite o valor para buscar na árvore: ";
                cin >> iDataToSearch;
                bool bIsFound = tree.search(iDataToSearch);
                if(bIsFound)
                    cout << "Elemento encontrado na árvore.";
                else
                    cout << "Elemento não encontrado na árvore.";
                break;
            }
            case 8:
            {
                bool bIsComplete = tree.isComplete();
                if(bIsComplete)
                    cout << "A árvore é completa.";
                else
                    cout << "A árvore não é completa.";
                break;
            }
            case 9:
            {
                bool bIsPerfect = tree.isPerfect();
                if(bIsPerfect)
                    cout << "A árvore é perfeita.";
                else
                    cout << "A árvore não é perfeita.";
                break;
            }
            case 10:
                // tree.displayBFS();
                break;
            case 11:
                // tree.convertAndSort("Bubble Sort");
                break;
            case 12:
                // tree.convertAndSort("Selection Sort");
                break;
            case 13:
                // tree.convertAndSort("Insertion Sort");
                break;
            case 14:
                // tree.convertAndSort("Shell Sort");
                break;
            case 15:
                return 0;
            default:
                cout << "Opção inválida." <<endl;
                break;
        }

        auto end = high_resolution_clock::now();
        auto elapsed = duration_cast<microseconds>(end - start);
        cout << "O tempo gasto na operação foi: "<< elapsed.count() << " microsegundos"<<endl;
    }
    return 0;
}