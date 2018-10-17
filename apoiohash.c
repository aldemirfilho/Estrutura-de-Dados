#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int value;
	struct Node *next;
	struct Node *previous;
}Node;

typedef struct hash_table
{
	Node *table[10000];
}Hash_Table;

Node *newNode(int x){
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = x;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

Hash_Table *create_hash_table()
{
	int i;
	Hash_Table *new_ht = (Hash_Table*) malloc(sizeof(Hash_Table));
	for(i = 0; i < 10000; i++)
	{
		new_ht->table[i] = newNode(i);
	}
	return new_ht;
}

Node *add_element(Node *inicio, int value)
{
	Node *node = newNode(value);
	if(inicio->next == NULL)
	{
		//printf("ifififif\n");
		node->value = value;
		node->next = NULL;
		node->previous = inicio;
		inicio->next = node;
		//printf("%d\n", node->value);
		return inicio;
	}
	else if(inicio->next != NULL)
	{
		Node *current = inicio;
		while(current->next != NULL)
		{
			current = current->next;
		}
		//printf("elselsle\n");
		current->next = node;
		node->value = value;
		node->next = NULL;
		node->previous = current;
		return inicio;
	}
}

void put(Hash_Table *ht,int num,int num_prime)
{
	int index;
	index = num % num_prime;
	ht->table[index] = add_element(ht->table[index], num);
}

void remove_(Hash_Table *ht, int num, int num_prime)
{
	int i;
	Node *aux;
	for(i = 0; i < num_prime; i++)
	{
		aux = ht->table[i];
		if(aux->next != NULL)
		{
			aux = aux->next;
			while(aux != NULL)
			{
				if(aux->value == num)
				{	
					Node *temp = aux;

					Node *nodeprevious = aux->previous;
					Node *nodenext = aux->next;

					if(aux->next == NULL)
					{
						nodeprevious->next = NULL;
					}
					if(aux->next != NULL)
					{
						nodeprevious->next = nodenext;
						nodenext->previous = nodeprevious;
					}
					free(temp);
					return;
				}
				aux = aux->next;
			}
		}
	}
}

void print_hash(Hash_Table *ht, int num_prime)
{
	int i;
	Node *aux;
	for(i = 0; i < num_prime; i++)
	{
		aux = ht->table[i];
		if(aux->next == NULL)
		{
			printf("[%d] -> NULL\n", i);
		}
		else
		{
			aux = aux->next;
			printf("[%d] -> ", i);
	    	while(aux != NULL)
	    	{
		        printf("%d -> ", aux->value);
		        aux = aux->next;
	  	  	}
	  	  	printf("NULL\n");
	  	}
	}
    printf("\n");	
}

void limpar(Hash_Table *ht)
{
	free(ht);
}

int main()
{
	printf("\n");
	int qntd, i;
	printf("Digite a quantida de elementos...\n");
	scanf("%d", &qntd);
	printf("\n");
	int num_prime, element;
	printf("Digite o numero primo que será usado...\n");
	scanf("%d", &num_prime);
	printf("\n");
	printf("Digite os elementos que irao compor a hash...\n");
	Hash_Table *ht = create_hash_table();
	for(i = 0; i < qntd; i++)
	{
		scanf("%d", &element);
		put(ht, element, num_prime);
	}
	printf("\n");
	printf("Hash atual\n");
	print_hash(ht, num_prime);
	printf("Deseja remover algum elemento?\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
	int op;
	scanf("%d", &op);
	printf("\n");
	if(op == 1)
	{
		printf("Digite o elemento que será removido...\n");
		int removed;
		scanf("%d", &removed);
		printf("\n");
		remove_(ht, removed, num_prime);
	}
	printf("Hash Atual\n");
	print_hash(ht, num_prime);
	return 0;
}