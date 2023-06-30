#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

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

// Função BubbleSort com impressão de cada passo
void bubbleSort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (vec[j] > vec[j+1]) {
                std::swap(vec[j], vec[j+1]);
                print_bars(vec); // impressão do vetor após cada troca
            }
        }
    }
}

int main() {
    std::vector<int> vec = {5, 3, 8, 4, 2, 7, 1, 6};
    bubbleSort(vec);
    return 0;
}
