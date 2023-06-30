// Lista encadea 1
#include<iostream>
// dados do aluno ,matricula, nome nota proximo
using std::cout;
using std::cin;
using std::string;
using std::endl;

struct Node
{
    int data;
    struct Node* next; /* um nó aponta para outro no, funciona como s
    tivessem em alocação continua na teoria (como uma lista)*/
};

void printList(struct Node*);
void addToList(struct Node*, int);

int main()
{
    struct Node* cabeca = nullptr; //ponteiro que começa
    struct Node* segundo = nullptr;
    struct Node* terceiro = nullptr;

    cabeca = (struct Node*) malloc(sizeof(struct Node));
    segundo = (struct Node*) malloc(sizeof(struct Node));
    terceiro = (struct Node*) malloc(sizeof(struct Node));

    cabeca -> data =  7;
    cabeca -> next = segundo;

    segundo -> data = 42;
    segundo -> next = terceiro;

    terceiro -> data = 666;
    terceiro -> next = nullptr;


    printList(cabeca);
    cout << "----------------" << endl;
    addToList(cabeca, 777);
    printList(cabeca);
    cout << "----------------" << endl;
    addToList(cabeca, 2023);
    printList(cabeca);
    cout << "----------------" << endl;

    free(terceiro);
    free(segundo);
    free(cabeca);


    return 0;
}

void printList(struct Node* sNode)
{
    while (sNode != nullptr)
    {
        cout << "Dado do nó: " << sNode->data << endl;

        sNode = sNode->next;
    }
}

void addToList(struct Node* elemento, int iValue)
{
    struct Node* proximo = nullptr;
    proximo = (struct Node*) malloc(sizeof(struct Node));
    proximo -> data = iValue;
    proximo -> next = nullptr;

    while (elemento->next != nullptr)
    {
        elemento = elemento->next;
    }

    elemento->next = proximo;
}
    
