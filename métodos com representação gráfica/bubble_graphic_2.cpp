#include <iostream>
#include <list>
#include <chrono>
#include <thread>
#include <algorithm>

// Função para encontrar o valor máximo na lista
int find_max(const std::list<int>& lst) {
    return *std::max_element(lst.begin(), lst.end());
}

// Função para imprimir a lista como barras de '#'
void print_bars(const std::list<int>& lst, bool is_final_call = false) {
    int max_value = find_max(lst);
    for (int i = max_value; i > 0; i--) {
        for (const auto& value : lst) {
            if (value >= i) {
                std::cout << "# ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "\n";
    }

    for (const auto& value : lst) { // imprime os valores numéricos abaixo de cada barra
        std::cout << value << " ";
    }

    std::cout << "\n------------------\n"; // separador para cada passo da ordenação

    std::this_thread::sleep_for(std::chrono::seconds(1)); // pausa a execução por 1 segundos

    if (!is_final_call) { // se não for a última chamada, limpa a tela
        std::system("clear");
    }
}

// Função BubbleSort com impressão de cada passo
void bubbleSort(std::list<int>& lst) {
    bool swapped;
    do {
        swapped = false;
        for (auto i = lst.begin(), j = std::next(i); j != lst.end(); ++i, ++j) {
            if (*i > *j) {
                std::swap(*i, *j);
                print_bars(lst); // impressão da lista após cada troca
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    std::list<int> lst = {5, 3, 8, 4, 2, 7, 1, 6};
    bubbleSort(lst);
    print_bars(lst, true); // impressão final da lista após a ordenação, marcada como última chamada
    return 0;
}




