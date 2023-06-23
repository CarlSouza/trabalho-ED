#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
////// ESTRUTURA BASICA DE ARVORE - REMOVER QUANDO FIZER MERGE DOS CODIGOS //////
/////////////////////////////////////////////////////////////////////////////////

struct TreeNode
{
    int iData;
    struct TreeNode* ptrLeft;
    struct TreeNode* ptrRight;
};


// Três tipos de sequenciamento de árvores: pré-ordem, pós-ordem, e em ordem
struct TreeNode* newNode(int iData)
{
    struct TreeNode* newNodePtr = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNodePtr->iData = iData;
    newNodePtr->ptrLeft = nullptr;
    newNodePtr->ptrRight = nullptr;

    return newNodePtr;
}


// node eh o node inicial da arvore
struct TreeNode* insertNode(struct TreeNode* node, int iVal)
{
    if(node == nullptr)
        return newNode(iVal);
    if(iVal < node->iData)
        node->ptrLeft = insertNode(node->ptrLeft, iVal);
    else
        node->ptrRight = insertNode(node->ptrRight, iVal);

    return node;
}


// Primeiro o nó à esquerda, depois o atual, depois à direita
void printTree(struct TreeNode* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) 
        return;

    printTree(ptrStartingNode->ptrLeft);
    cout << " " << ptrStartingNode->iData;
    printTree(ptrStartingNode->ptrRight);
}


/////////////////////////////////////////////////////////////////////////////////
////////// ESTRUTURA DE LISTA DUPLAMENTE ENCADEADA PARA TAREFAS 13 A 16 /////////
/////////////////////////////////////////////////////////////////////////////////

// Estrutura de node das listas duplamente encadeadas
struct ListNode
{
    int iData;
    struct ListNode* ptrNext;
    struct ListNode* ptrPrev;
};


// Funcao para criar novos nodes
struct ListNode* createNode(int iVal, struct ListNode* next, struct ListNode* prev)
{
    struct ListNode* newNode = new struct ListNode;
    newNode->iData = iVal;
    newNode->ptrNext = next;
    newNode->ptrPrev = prev;

    return newNode;
}


// Funcao para inserir novos nodes a lista duplamente encadeada
void insertListNode(struct ListNode** head, int iVal)
{
    // Criamos um novo node
    struct ListNode* newNode = createNode(iVal, nullptr, nullptr);

    // Se a lista esta vazia, newNode eh o head
    if((*head) == nullptr)
        (*head) = newNode;
    else
    {
        // Percorremos a lista ate o final
        struct ListNode* current = (*head);
        while(current->ptrNext != nullptr)
            current = current->ptrNext;

        // e adicionamos o novo node apos o "antigo" ultimo 
        current->ptrNext = newNode;
        newNode->ptrPrev = current;
    }

    return;
}


// Funcao para trocar dois nodes de uma lista encadeada de posicao
void swapListNodes(struct ListNode** head, struct ListNode* Node1, struct ListNode* Node2)
{
    if(Node1 == nullptr || Node2 == nullptr || Node1 == Node2)
    {
        cout << "Ao menos um dos nodes fornecidos eh nulo ou eles sao iguais." << endl;
        return;
    }
    // A funcao considera que node1 vem antes de node2

        // Dois casos
    // Node1 e Node2 sao adjacentes
    if(Node1->ptrNext == Node2)
    {
        // Atualizamos os ponteiros "externos" a node1 e node2
        if(Node1->ptrPrev != nullptr)
        {
            Node2->ptrPrev = Node1->ptrPrev;
            Node1->ptrPrev->ptrNext = Node2;
        }
        else
            Node2->ptrPrev = nullptr;

        if(Node2->ptrNext != nullptr)
        {
            Node1->ptrNext = Node2->ptrNext;
            Node2->ptrNext->ptrPrev = Node1;
        }
        else
            Node1->ptrNext = nullptr;

        // Atualizar os ponteiros "internos" a node1 e node2
        Node2->ptrNext = Node1;
        Node1->ptrPrev = Node2;

        // Atualizar a cabeca da lista, se necessario
        if((*head) == Node1)
            (*head) = Node2;
    }

    // Node1 e Node2 nao sao adjacentes
    else
    {
            // Alterando os ponteiros que apontam para Node1 e Node2:
        // Antecessor -> Node1 ==> Anterior -> Node2
        if(Node1->ptrPrev != nullptr)
            Node1->ptrPrev->ptrNext = Node2;
        // Node1 <- Sucessor ==> Node2 <- Sucessor
        Node1->ptrNext->ptrPrev = Node2;
        // Antecessor -> Node2 ==> Antecessor -> Node1
        Node2->ptrPrev->ptrNext = Node1;
        // Node2 <- Sucessor ==> Node1 <- Sucessor
        if(Node2->ptrNext != nullptr)
            Node2->ptrNext->ptrPrev = Node1;

            // Alterando os ponteiros de Node1 e Node2
        // Ponteiro temporario para node anterior a Node1
        struct ListNode* ptrAntNode1 = Node1->ptrPrev;
        // Anterior_de_node1 <- Node1 ==> Anterior_de_node2 <- Node1
        Node1->ptrPrev = Node2->ptrPrev;
        // Anterior_de_node2 <- Node2 ==> Anterior_de_node1 <- Node2
        Node2->ptrPrev = ptrAntNode1;
        
        // Ponteiro temporario para node posterior a Node1
        struct ListNode* ptrPosNode1 = Node1->ptrNext;
        // Node1 -> Posterior_de_node1 ==> Node1 -> Posterior_de_node2
        Node1->ptrNext = Node2->ptrNext;
        // Node2 -> Posterior_de_node2 ==> Node2 -> Posterior_de_node1
        Node2->ptrNext = ptrPosNode1;

        // Atualizar a cabeca da lista, se necessario
        if((*head) == Node1)
            (*head) = Node2;        // Ponteiro de head aponta para Node2, o novo head
    }

    return;
}


// Funcao para imprimir a lista
void printList(struct ListNode* head)
{
    if(head == nullptr)
        cout << "A lista esta vazia!" << endl;

    while(head != nullptr)
    {
        cout << head->iData << " ";
        head = head->ptrNext;
    }
    cout << endl;

    return;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// TAREFA 13 ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// Funcao de ordenacao em BUBBLE SORT
void bubbleSort(struct ListNode** head)
{
    // Ponteiro para o maior valor da lista
    struct ListNode* ptrLarger = nullptr;
    // Ponteiro para o valor atual do loop ("next de ptrLarger")
    struct ListNode* ptrCurrent = nullptr;
    // Booleano para indicar se lista esta desordenada (true por padrao)
    bool bUnordered = true;

    // Enquanto a lista esta desordenada, ela eh percorrida. 
    // Se a funcao de swap eh acionada pelo menos uma vez, eh pq a lista esta desordenada. O status de desordem eh "verdadeiro".
    // Se a funcao de swap nao eh acionada, eh pq a lista esta ordenada. O status de desordem eh "false" e o loop termina.
    while(bUnordered)
    {
        // A cada loop, reiniciamos os ponteiros e o status de ordenacao
        ptrLarger = (*head);
        ptrCurrent = (*head)->ptrNext;
        bUnordered = false;

        // A lista eh percorrida ate o ponteiro do maior valor chegar ao ultimo elemento da lista
        while(ptrLarger->ptrNext != nullptr)
        {
            // Se o maior valor encontrado ate agora (ptrLarger) for maior do que o valor seguinte a ele (ptrCurrent):
            if(ptrLarger->iData > ptrCurrent->iData)
                {   
                    swapListNodes(head, ptrLarger, ptrCurrent);       // trocamos eles de posicao;
                    bUnordered = true;                                // trocamos o status de desordenado para verdadeiro

                    ptrCurrent = ptrCurrent->ptrNext;                 // avancamos o ponteiro atual para o seu "proximo", pois 
                                                                      // com o swap ele passa a ficar atras de ptrLarger
                }
            // Caso contrario, o maior valor passa a ser o do ponteiro atual
            else
                ptrLarger = ptrCurrent;
            
            // Avancamos o ponteiro atual para o proximo node, o "proximo" de ptrLarger
            ptrCurrent = ptrCurrent->ptrNext;
        }
    }

    return;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// TAREFA 14 ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// Funcao de ordenacao em SELECTION SORT
void selectionSort(struct ListNode** head)
{
    // Ponteiro para o node externo
    struct ListNode* ptrOuter = (*head);
    // Ponteiro para o node interno 
    struct ListNode* ptrInner = nullptr;

    // Enquanto nao chegarmos ao final da lista externa
    while(ptrOuter != nullptr)
    {
        // Ponteiro iterno comeca apontando para o "proximo" do ponteiro externo
        ptrInner = ptrOuter->ptrNext;
        // Enquanto não chegarmos ao final da lista interna
        while(ptrInner != nullptr)
        {
            // Verifica se o valor do node externo eh maior que o valor do node interno
            if(ptrOuter->iData > ptrInner->iData)
            {
                // Cria um ponteiro temporario para o node interno
                struct ListNode* ptrTemp = ptrInner;

                // Chama uma funcao para trocar os nodes de posicao
                swapListNodes(head, ptrOuter, ptrInner);

                // Atualiza o ponteiro externo para o node temporario (para continuar a partir desse ponto)
                ptrOuter = ptrTemp;
                // Atualiza o ponteiro interno para o proximo node apos o node temporario/externo        
                ptrInner = ptrTemp->ptrNext;
            }
            // Avanca para o proximo node interno
            ptrInner = ptrInner->ptrNext;
        }
        // Avanca para o proximo node externo
        ptrOuter = ptrOuter->ptrNext;
    }

    return;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// TAREFA 15 ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// Funcao de ordenacao em INSERTION SORT
void insertionSort(struct ListNode** head)
{
    // Verificar se a lista esta vazia ou se possui apenas um elemento
    if ((*head) == nullptr || (*head)->ptrNext == nullptr)
    {
        // Caso base: a lista está vazia ou possui apenas um elemento. Nesse caso, a lista ja esta ordenada, entao retornamos imediatamente.
        return;
    }
    
    // ptrOrdered aponta para o node atualmente sendo verificado na parte "ordenada" da lista
    struct ListNode* ptrOrdered = (*head);
    // ptrUnordered ira apontar para os nodes que serao realocados dentro da lista ordenada
    struct ListNode* ptrUnordered = nullptr;

    // Continuar enquanto ainda houver nodes nao verificados na lista
    while(ptrOrdered != nullptr)
    {
        // Verificar se o node atual (ptrOrdered) esta fora de ordem em relação ao node anterior (ptrOrdered->ptrPrev)
        if(ptrOrdered->ptrPrev != nullptr && ptrOrdered->iData < ptrOrdered->ptrPrev->iData)
        {
            // Se o node atual esta fora de ordem, ptrUnordered aponta para ele e inicia a operacao de realocacao
            ptrUnordered = ptrOrdered;

            // Chama a funcao swapNode para trocar o node atual (ptrOrdered) com o node anterior (ptrOrdered->ptrPrev)
            swapListNodes(head, ptrOrdered->ptrPrev, ptrOrdered);

            // Continuar a trocar o node ptrUnordered para tras ate encontrar sua posicao correta na lista ordenada
            while(ptrUnordered->ptrPrev != nullptr && ptrUnordered->iData < ptrUnordered->ptrPrev->iData)
            {
                // Chama a função swapNode para trocar o node ptrUnordered com o node anterior (ptrUnordered->ptrPrev)
                swapListNodes(head, ptrUnordered->ptrPrev, ptrUnordered);
            }
        }
        // Mover para o proximo node na lista nao ordenada
        ptrOrdered = ptrOrdered->ptrNext;
    }

    return;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// TAREFA 16 ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// Funcao de ordenacao em SHELL SORT
void shellSort(struct ListNode** head)
{
    struct ListNode* ptrCurrent = nullptr;

    if((*head) == nullptr || (*head)->ptrNext == nullptr)
        return;

    struct ListNode* ptrTemp = nullptr;
    struct ListNode* ptrSlow = nullptr;
    struct ListNode* ptrFast = nullptr;
    bool bUnordered = true;

    while(bUnordered)
    {
        bUnordered = false;
        ptrFast = (*head);
        ptrSlow = (*head);
        ptrCurrent = (*head);

        cout << "Inicio loop " << ptrSlow->iData << " " << ptrFast->iData << " " << endl;

        while(ptrFast->ptrNext != nullptr && ptrFast->ptrNext->ptrNext != nullptr && ptrFast->ptrNext != ptrTemp && ptrFast->ptrNext->ptrNext != ptrTemp)
        {
            ptrFast = ptrFast->ptrNext->ptrNext;
            ptrSlow = ptrSlow->ptrNext;
        }

        // Salvar o valor de ptrSlow em ptrTemp antes de ser modificado
        ptrTemp = ptrSlow;
        cout << "Apos divisao " << ptrSlow->iData << " " << ptrFast->iData << " " << ptrTemp->iData << endl;

        if(ptrSlow == ptrFast)
            break;

        while(ptrSlow->ptrNext != nullptr)
        {
            if(ptrCurrent->iData > ptrSlow->iData)
                {
                    if(ptrSlow == ptrTemp)
                        ptrTemp = ptrCurrent;

                    struct ListNode* TempSlow = ptrSlow;
                    swapListNodes(head, ptrCurrent, ptrSlow);
                    bUnordered = true;
                    ptrSlow = ptrCurrent;
                    ptrCurrent = TempSlow;
                }
            
            cout << "Trocou " << ptrSlow->iData << " <-> " << ptrCurrent->iData << " T: " << ptrTemp->iData << " =        ";

            ptrSlow = ptrSlow->ptrNext;
            ptrCurrent = ptrCurrent->ptrNext;

            printList(*head);
        }

    }
    bubbleSort(head);
    printList(*head);

    return;
}


/////////////////////////////////////////////////////////////////////////////////
////////////////////////// FUNCOES CENTRAIS DE 13 A 16 //////////////////////////
/////////////////////////////////////////////////////////////////////////////////

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
}


// Funcao principal para responder as perguntas de 13 a 16:
// Aciona a funcao que transforma a arvore em lista;
// Aciona a funcao escolhida pelo usuario para ordenar a lista.
void sort(struct TreeNode* root, int iTypeSort)
{
    // Criamos um head para a lista duplamente encadeada
    struct ListNode* head = nullptr;

    // Adicionamos os nodes na arvore na lista
    treeToList(root, &head);

    // Imprimimos a lista ainda nao ordenada
    // printList(head);
    // cout << endl;

    // Escolhe a forma de ordenacao
    switch(iTypeSort)
    {
        case 11:
            bubbleSort(&head);
            printList(head);
            break;
        case 12:
            selectionSort(&head);
            printList(head);
            break;
        case 13:
            insertionSort(&head);
            printList(head);
            break;
        case 14:
            shellSort(&head);
            printList(head);
            break;
        default:
            break;
    }

    return;
}


int main()
{
    // Exemplo de uma arvore
    struct TreeNode* root = newNode(42);

    //int iElementos[] = {-7, 19, 0, 12, -25, 8, -14, 2, 17, -6, 22, 10, -31, 15, -9, 27, -5, 13, -18, 1, -3, 11, -20, 6, 14, -29, 4, -16, 23, 7};
    int iElementos[] = {-7, 19, 0, 12, -25, 8, -14, 2, 17, -6};
    for(int i = 0; i < 10; i++)
        insertNode(root, iElementos[i]);

    cout << "\n============================================================================================\n" << endl;

    // Printando a arvore 
    cout << "A árvore 'In-Order': ";
    printTree(root);
    cout << endl;

    cout << "\n============================================================================================\n" << endl;

    cout << "BUBBLE SORT \n" << endl;
    sort(root, 11);

    cout << "\n============================================================================================\n" << endl;

    cout << "SELECTION SORT \n" << endl;
    sort(root, 12);

    cout << "\n============================================================================================\n" << endl;

    cout << "INSERTION SORT \n" << endl;
    sort(root, 13);

    cout << "\n============================================================================================\n" << endl;

    // Nao esta pronto. Estou tentando fazer sem usar uma funcao que calcula o tamanho da lista
    cout << "SHELL SORT \n" << endl;
    //sort(root, 14);

    cout << "\n============================================================================================\n" << endl;
    return 0;
}