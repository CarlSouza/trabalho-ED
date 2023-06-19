#include <iostream>
#include <chrono> 
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
    cout << "==========================="<<endl;
    cout << "  Explorador de Árvores"<<endl;
    cout << "==========================="<<endl;
    cout << "1. Construir uma árvore binária a partir de um arquivo texto"<<endl;
    cout << "2. Construir uma árvore binária a partir de dados digitados pelo usuário"<<endl;
    cout << "3. Informar a altura da árvore"<<endl;
    cout << "4. Informar o tamanho da árvore"<<endl;
    cout << "5. Inserir um elemento fornecido pelo usuário"<<endl;
    cout << "6. Remover um elemento fornecido pelo usuário"<<endl;
    cout << "7. Buscar o endereço de memória de um elemento fornecido pelo usuário"<<endl;
    cout << "8. Informar se a árvore é completa"<<endl;
    cout << "9. Informar se a árvore é perfeita"<<endl;
    cout << "10. Exibir a árvore utilizando BFS"<<endl;
    cout << "11. Converter a árvore em uma lista e ordenar com Bubble Sort"<<endl;
    cout << "12. Converter a árvore em uma lista e ordenar com Selection Sort"<<endl;
    cout << "13. Converter a árvore em uma lista e ordenar com Insertion Sort"<<endl;
    cout << "14. Converter a árvore em uma lista e ordenar com Shell Sort"<<endl;
    cout << "15. Sair"<<endl;
}

int main() {
    BinaryTree tree;
    while (true) {
        print_menu();
        cout << "Selecione uma opção: entre 1 e 15  "<<endl;
        int iOption;
        cin >> iOption;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, insira um número entre 1 e 15 !!."<<endl;
            continue;
        }

        auto start = std::chrono::high_resolution_clock::now();

        switch (iOption) {
            case 1:
                // tree.buildFromTextFile();
                break;
            case 2:
                // tree.buildFromUserInput();
                break;
            case 3:
                // tree.getHeight();
                break;
            case 4:
                // tree.getSize();
                break;
            case 5:    
                int dataToInsert;
                cout << "Digite o valor para inserir na árvore: ";
                cin >> dataToInsert;
                tree.insert(dataToInsert);
                cout << "Valor inserido com sucesso!" << endl;
                break;
            case 6:
                int dataToRemove;
                cout << "Digite o valor para remover da árvore: ";
                cin >> dataToRemove;
                if (tree.remove(dataToRemove)) {
                    cout << "Valor removido com sucesso!" << endl;
                } else {
                    cout << "Falha ao remover valor." << endl;
                }
                break;
            case 7:
                // tree.getMemoryAddress();
                break;
            case 8:
                // tree.checkIfComplete();
                break;
            case 9:
                // tree.checkIfPerfect();
                break;
            case 10:
                // tree.displayTreeUsingBFS();
                break;
            case 11:
                // tree.convertTreeToListAndSortWithBubbleSort();
                break;
            case 12:
                // tree.convertTreeToListAndSortWithSelectionSort();
                break;
            case 13:
                // tree.convertTreeToListAndSortWithInsertionSort();
                break;
            case 14:
                // tree.convertTreeToListAndSortWithShellSort();
                break;
            case 15:
                exit(0);
            default:
                cout << "Entrada inválida. Por favor, insira um número entre 1 e 15 !!"<<endl;
        }

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << "Tempo de processamento: " << duration.count() << " microssegundos.\n";
    }
    return 0;
}


