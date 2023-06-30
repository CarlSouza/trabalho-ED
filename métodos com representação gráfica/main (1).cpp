#include <iostream>
#include <chrono>
#include <thread>

// Definição da estrutura do nó da lista encadeada
struct Node {
    int data;
    Node* next;
};

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Função para inserir um novo nó no início da lista
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Função para encontrar o valor máximo na lista
int findMax(Node* head) {
    int max_value = head->data;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }
    return max_value;
}

// Função para imprimir a lista como barras de '#'
void printBars(Node* head) {
    int max_value = findMax(head);
    Node* current = head;
    while (max_value > 0) {
        while (current != nullptr) {
            if (current->data >= max_value) {
                std::cout << "# ";
            } else {
                std::cout << "  ";
            }
            current = current->next;
        }
        std::cout << "\n";
        current = head;
        max_value--;
    }

    current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n------------------\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

// Função BubbleSort com impressão de cada passo
void bubbleSort(Node*& head) {
    int n = 0;
    Node* current = head;
    while (current != nullptr) {
        n++;
        current = current->next;
    }

    for (int i = 0; i < n-1; i++) {
        Node* current = head;
        for (int j = 0; j < n-i-1; j++) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                printBars(head);
            }
            current = current->next;
        }
    }
}

int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 7);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 5);
    bubbleSort(head);
    
    return 0;
}

