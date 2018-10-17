#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/////////////////---------LISTA--------/////////////////


typedef struct node_
{
	int value;
	struct Node *next; //ponteiro de um nó
	struct Node *previous; //ponteiro de um nó	
}Node;

typedef struct linkedlist_
{
	int size;
	Node *front;
	Node *back;
}LinkedList;

Node *new_node (int x)
{
	Node *node = (Node*) malloc(sizeof(Node));
	node->value = x;
	node->next = NULL;
	node->previous = NULL;
	return node; 
}

LinkedList *new_list ()
{
	LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
	list->size = 0;
	list->front = NULL;
	list->back = NULL;
	return list;
}

int isEmpty(LinkedList *list)
{
	if(list == NULL) 
		return 1;
	return (list->size == 0);
}

int search_list(Node *head, int item)
{
	int cont = 0;
	while(head != NULL)
	{
		if(head->value == item)
		{	
			//cont++;
			return cont;
		}
		cont++;
		head = head->next;
	}
}

void add_front(LinkedList *list, int value)
{
	Node *node = new_node(value);
	if(list->size == 0)
	{
		list->size = 1;
		list->front = list->back = node;
	}
	else
	{
		node->next = list->front;
		list->front->previous = node;
		list->front = node;
		list->size++;
	}
}

void add_back (LinkedList *list, int value)
{
	Node *node = new_node(value);
	if(list->size == 0)
	{
		list->size = 1;
		list->front = list->back = node;
	}
	else 
	{
		node->previous = list->back;
		list->back->next = node;
		list->back = node;
		list->size++;
	}
}


void remove_elemento (LinkedList *list, int value)
{
	if(list == NULL || list->size == 0) 
		return;
	Node *aux;
	Node *current;
	if(list->front->value == value)
	{
		aux = list->front;
		list->front = list->front->next;
		list->front->previous = NULL;
		list->size--;
		free(aux);
	}
	else if(list->back->value == value)
	{
		aux = list->back;
		list->back = list->back->previous;
		list->back->next = NULL;
		list->size--;
		free(aux);
	}
	else 
	{
		current = list->front;
		while(current != NULL)
		{
			if(current->value == value)
			{
				Node *nodeprevious = current->previous;
				Node *nodenext = current->next;
				nodeprevious->next = nodenext;
				nodenext->previous = nodeprevious;
				list->size--;
				free(current);
				return;
			}
			current = current->next;
		}
	}
}

void print_crescente (LinkedList *list)
{
	if(list == NULL || list->size == 0) 
		return;
	Node *node = list->front;
	while(node != NULL)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
	puts("");
}

void print_decrescente (LinkedList *list)
{
	if(list == NULL || list->size == 0)
		return;
	Node *node = list->back;
	while(node != NULL)
	{
		printf("%d ", node->value);
		node = node->previous;
	}
	puts("");
}

int main()
{
	int qntd, i;
	printf("\n");
	printf("Digite a quantidade de elementos da lista...\n");
	scanf("%d", &qntd);
	printf("\n");
	int elements[qntd];
	LinkedList *list = new_list();
	printf("Digite os elementos da lista...\n");
	for(i = 0; i < qntd; i++)
	{
		scanf("%d", &elements[i]);
		add_back(list, elements[i]);
	}
	printf("\n");
	print_crescente(list);
	printf("Deseja remover alguma elemento?\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
	int op;
	scanf("%d", &op);
	if(op == 1)
	{
		printf("\n");
		printf("Digite o elemento a ser removido...\n");
		int remover;
		scanf("%d", &remover);
		remove_elemento(list, remover);
		printf("\n");
	}
	printf("Lista atual:\n");
	printf("\n");
	print_crescente(list);
	int procurado, pos;
	printf("Digite o elemento a ser procurado...\n");
	scanf("%d", &procurado);
	pos = search_list(list->front, procurado);
	printf("\n");
	printf("Posicao -> [%d]\n", pos);
	return 0;	
}
