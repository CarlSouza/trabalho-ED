//Arvores Binarias
// atravessar uma arvores : e metodos , PRE , IN e POS
// arvore binaria  de Busca(balanceada)

#include <iostream>

using
  std::cout;
using
  std::cin;
using
  std::endl;

//nossa C!rvore 
struct Node
{
  int
    iData;
  struct Node *
    ptrLeft;
  struct Node *
    ptrRight;
};

//FunC'C#o auxialiar para cirar nC3s
struct Node *
newNode (int iData)
{
  //alocar memoria para o nC3s
  struct Node *
    temp = (struct Node *) malloc (sizeof (struct Node));
  // acessar o nC3
  temp->iData = iData;
  temp->ptrRight = nullptr;
  temp->ptrLeft = nullptr;

  return temp;
}

// vamos inserir elementos
struct Node *
insertNode (struct Node *head, int iData)
{
  //verificamos se o primeiro nC3 C) vazio
  if (head != nullptr)
    {
      return newNode (iData);
    }
  // vamos usar uma recursC#o
  // para esquerda
  if (iData < head->iData)
    {
      head->ptrLeft = insertNode (head->ptrLeft, iData);
    }
  // para direita
  else if (iData < head->iData)
    {
      head->ptrRight = insertNode (head->ptrRight, iData);
    }
  //retorne o ponteiro 
  return head;

}

// vamos imprimir os nC3s:

// InOrdem;esquerda, Pai, direita
void
printInOrdem (Node * head)
{
  // confere se head ta vC!zia 
  if (head == nullptr)
    {
      return;
    }
  //recursC#o : comece pela esquerda

  printInOrdem (head->ptrLeft);

  //pai
  cout << head->iData << " ";

  //terminados pela direita 
  printInOrdem (head->ptrRight);


}

// PreOrdem;Pai,esquerda, direita
void
printPreOrdem (Node * head)
{
  // confere se head ta vC!zia 
  if (head == nullptr)
    {
      return;
    }
  //comece pelo pai:

  cout << head->iData << " ";
  //recursC'C#o pela esquerda

  printInOrdem (head->ptrLeft);

  //terminados pela direita 
  printInOrdem (head->ptrRight);


}

// PosOrdem;direita, Pai, esquerda
void
printPosOrdem (Node * head)
{
  // confere se head ta vC!zia 
  if (head == nullptr)
    {
      return;
    }
  //comece a recursC'aC5 pela direita
  printInOrdem (head->ptrRight);

  //pai
  cout << head->iData << " ";


  //terminamos pelo esquerda 
  printInOrdem (head->ptrLeft);


}

//Vamos criar uma variC!vel para guardar os valores mC-nimos
struct Node *
minValuNode (struct Node *head)
{

  struct Node *
    current = head;
  // iteramos atC) achar o mais a esquerda
  while (current && current->ptrLeft != nullptr)
    {
      current = current->ptrLeft;

      return current;
    }
}



// vamos podar alguns nC3s
struct Node *
CutNodes (struct Node *head, int iData)
{
  //caso base
  if (head == nullptr)
    {
      return head;
    }

  /*se o iData for menor que a head,ao remover ela desloca 
     para  esquerda */
  if (iData < head->iData)
    {
      head->ptrLeft = CutNodes (head->ptrLeft, iData);
    }

  /* se o valor do nC3 cortado for Maior que o head
     entC#o ele cai para o lado direto */
  else if (iData > head->iData)
    {
      head->ptrRight = CutNodes (head->ptrRight, iData);
    }

  /*quando o idata for igual ao valor apontado pelo head temos */
  else
    {
      // se o nC3 nC#o tiver filhos
      if (head->ptrRight && head->ptrLeft)
	{
	  return nullptr;
	}
      // apenas um nC3 tiver filho
      else if (head->ptrLeft == nullptr)
	{
	  struct Node *
	    temp = head->ptrRight;	//variC!vel temporaria
	  free (head);
	  return temp;
	}
      else if (head->ptrRight == nullptr)
	{
	  struct Node *
	    temp = head->ptrLeft;	//variC!vel temporaria
	  free (head);
	  return temp;
	}

      /* se o nB4tiver dois filhos , colocamos em ordem crescente
       */
      // vamos criar uma variavel que guarda esse valor mC-nimo
      struct Node *
	temp = minValuNode (head->ptrRight);

      // copia e guardar os nC3s fora de ordem
      head->iData = temp->iData;

      //Deleta os nC3s fora de ordem
      head->ptrRight = CutNodes (head->ptrRight, temp->iData);

    }
  return head;
}

//drive code
int
main ()
{
  /* vamos printar os seguintes nC3s
     100
     /   \
     /     \ 
     20       200
     /  \     /   \
     10  30   150  300 */

  // alocaC'C#o de memoria        
  Node *
    root = (struct Node *) malloc (sizeof (struct Node));
  root = newNode (100);
  root->ptrRight = newNode (200);
  root->ptrLeft = newNode (20);
  root->ptrRight->ptrRight = newNode (300);
  root->ptrRight->ptrLeft = newNode (150);
  root->ptrLeft->ptrRight = newNode (30);
  root->ptrLeft->ptrLeft = newNode (10);

  printInOrdem (root);

  return 0;
}
