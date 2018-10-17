#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree 
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
}Binary_tree;

Binary_tree *create_binary_tree(int item, Binary_tree *left, Binary_tree *right)
{
	Binary_tree *bt = (Binary_tree*) malloc(sizeof(Binary_tree));
	bt->item = item;
	bt->left = left;
	bt->right = right;
	return bt;
}

int is_empty(Binary_tree *bt)
{
	if(bt == NULL)
	{
		return 1;
	}
	else
		return 0;
}

Binary_tree *add(Binary_tree *bt, int item)
{
	if (bt == NULL) 
	{
		bt = create_binary_tree(item, NULL, NULL);
	} 
	else if (bt->item > item) 
	{
		bt->left = add(bt->left, item);
	} 
	else 
	{
		bt->right = add(bt->right, item);
	}
	return bt;
}

Binary_tree* search(Binary_tree *bt, int item)
{
	if ((bt == NULL) || (bt->item == item)) 
	{
		return bt;
	} 
	else if (bt->item > item) 
	{
		return search(bt->left, item);
	} 
	else 
	{
		return search(bt->right, item);
	}
}

void print_in_order(Binary_tree *bt)
{
	if (!is_empty(bt)) 
	{
		print_in_order(bt->left);
		printf(" %d ", bt->item);
		print_in_order(bt->right);
	}
}

void print_pre_order(Binary_tree *bt)
{
	//printf(" (");
	if (!is_empty(bt)) 
	{
		printf(" %d ", bt->item);
		print_pre_order(bt->left);
		print_pre_order(bt->right);
	}
	//printf(") ");
}

void print_post_order(Binary_tree *bt)
{
	if (!is_empty(bt)) 
	{
		print_post_order(bt->left);
		print_post_order(bt->right);
		printf(" %d ", bt->item);
	}
}


Binary_tree *remove_atual(Binary_tree *atual)
{
	Binary_tree *aux1, *aux2;
	if(atual->left == NULL)
	{
		aux2 = atual->right;
		free(atual);
		return aux2;
	}
	aux1 = atual;
	aux2 = atual->left;
	while(aux2->right != NULL)
	{
		aux1 = aux2;
		aux2 = aux2->right;
	}
	if(aux1 != atual)
	{
		aux1->right = aux2->left;
		aux2->left = atual->left;
	}
	aux2->right = atual->right;
	free(atual);
	return aux2;
}

int remove_(Binary_tree *bt, int num)
{
	if(bt == NULL) return 0;
	Binary_tree *anterior = NULL;
	Binary_tree *atual = bt;
	while(atual != NULL)
	{
		if(num == atual->item)
		{
			if(atual == bt)
				bt = remove_atual(atual);
			else
			{
				if(anterior->right == atual)
					anterior->right = remove_atual(atual);
				else
					anterior->left = remove_atual(atual);
			}
			return 1;
		}
		anterior= atual;
		if(num > atual->item)
			atual = atual->right;
		else
			atual = atual->left;
	}
}

int main()
{
	printf("\n");
	int qntd, i, element;
	printf("Digite a quantida de elementos...\n");
	scanf("%d", &qntd);
	printf("\n");
	printf("Digite os elementos que irao compor a tree...\n");
	scanf("%d", &element);
	Binary_tree *bt = create_binary_tree(element, NULL, NULL);
	Binary_tree *raiz_principal = bt;
	for(i = 0; i < qntd - 1; i++)
	{
		scanf("%d", &element);
		add(bt, element);
	}
	printf("\n");
	printf("Arvore atual:\n");
	printf("Printando em pre ordem:\n");
	print_pre_order(bt);
	printf("\n");
	printf("Printando em ordem:\n");
	print_in_order(bt);
	printf("\n");
	printf("Printando em pos ordem:\n");
	print_post_order(bt);
	printf("\n");
	printf("\n");
	printf("Deseja buscar algum elemento\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
	int op;
	scanf("%d", &op);
	printf("\n");
	if(op == 1)
	{
		printf("Digite o elemento que será procurado...\n");
		int procurado;
		scanf("%d", &procurado);
		printf("\n");
		Binary_tree *no_encontrado;
		no_encontrado = search(raiz_principal, procurado);
		if(no_encontrado != NULL)
			printf("encontrado: %d\n", no_encontrado->item);
		else
			printf("No nao encontrado.\n");
	}
	printf("Deseja remover algum elemento\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
	scanf("%d", &op);
	printf("\n");
	if(op == 1)
	{
		printf("Digite o elemento que será removido...\n");
		int removido;
		scanf("%d", &removido);
		printf("\n");
		remove_(raiz_principal, removido);
	}
	printf("Arvore atual:\n");
	printf("Printando em pre ordem:\n");
	print_pre_order(bt);
	printf("\n");
	return 0;
}