/*01.O programa deve oferecer um menu ASCII para o usuário com as opções de uso*/

#include <iostream>
#include <cstdlib>

using  std::cout;
using  std::endl;
using  std::cin;

// aqui vamor criar uma função que retorna as opções
void print_menu() {
    cout << "==========================="<<endl;
    cout << "  Explorador de Árvores"<<endl ;
    cout << "==========================="<<endl;
    cout << "1. Construir uma árvore binária a partir de um arquivo texto"<<endl;
    cout << "2. Construir uma árvore binária a partir de dados digitados pelo usuário"<<endl;
    cout << "3. Informar a altura da árvore"<<endl;
    cout << "4. Informar o tamanho da árvore"<<endl;
    cout << "5. Inserir um elemento fornecido pelo usuário"<<endl;
    cout << "6. Remover um elemento fornecido pelo usuário"<<endl;
    cout << "7. Buscar o endereço de memória de um elemento fornecido pelo usuário"<<endl;
    cout << "8. Informar se a árvore é completa<<endl"<<endl;
    cout << "9. Informar se a árvore é perfeita"<<endl;
    cout << "10. Exibir a árvore utilizando BFS"<<endl;
    cout << "11. Converter a árvore em uma lista e ordenar com Bubble Sort"<<endl;
    cout << "12. Converter a árvore em uma lista e ordenar com Selection Sort"<<endl;
    cout << "13. Converter a árvore em uma lista e ordenar com Insertion Sort"<<endl;
    cout << "14. Converter a árvore em uma lista e ordenar com Shell Sort"<<endl;
    cout << "15. Sair"<<endl;
}

int main() {
    while (true) {
        print_menu();
        cout << "Selecione uma opção: ";
        int iOption;// notação hungará
        cin >> iOption;
        switch (iOption) {
            case 1:
                // Aqui você coloca o código para construir a árvore binária a partir de um arquivo de texto.
                break;
            // Adicione os outros casos aqui...
            case 15:
                exit(0);
            default:
                cout << "Opção inválida. Por favor, escolha novamente."<<endl;
        }
    }
    return 0;
}
