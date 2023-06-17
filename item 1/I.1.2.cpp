#include <iostream>
#include <cstdlib>
#include <limits>  
#include "BinaryTree.h"

using  std::cout;
using  std::cin;
using  std::endl;
using  std::numeric_limits;
using  std::streamsize;

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
        int iOption;//notação Húngara
        cin >> iOption;
        if(cin.fail()) { // verifica se a entrada falhou
            cin.clear(); // limpa o erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta a entrada
            cout << "Entrada inválida. Por favor, insira um número entre 1 e 15 !!."<<endl;
            continue;
        }
        switch (iOption) {
            case 1:
                // Aqui  colocamos o código para construir a árvore binária a partir de um arquivo de texto.
                break;
            // Aqui colocamos os outros casos aqui...
            case 5:
                int data;
                cout << "Digite o valor para inserir na árvore: ";
                cin >> data;
                tree.insert(data);
                cout << "Valor inserido com sucesso!" << endl;
                break;
            case 15:
                exit(0);
            default:' ';
                cout << "Entrada inválida. Por favor, insira um número entre 1 e 15 !!"<<endl;
        }
    }
    return 0;
}
