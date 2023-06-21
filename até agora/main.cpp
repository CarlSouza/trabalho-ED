#include <iostream>
#include <chrono> 
#include "BinaryTree.h"

// Aqui importamos todas as bibliótecas necessárias

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

// Definindo as classes necessárias para o funcionamento

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

// Aqui temos a função para imprimir o nosso  menu !

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
            // Aqui nós temos um loop que roda indefinidamente até o usuário escolher a opção de saída.
            // Ele pede a opção do usuário e realiza a operação correspondente.

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
                break;
            // E assim por diante, cada caso corresponde a uma opção de menu e chama a função correspondente.
            // Alguns desses casos não estão implementados, então eles não fazem nada no momento.
            case 15:
                return 0;
            default:
                cout << "Opção inválida." <<endl;
                break;
        }
        // Aqui nós calculamos quanto tempo levou para realizar a operação
        // Isso pode ser útil para comparar o desempenho de diferentes operações ou implementações

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "O tempo gasto na operação foi: "<< elapsed.count() << " microsegundos"<<endl;
    }

    return 0;
}

