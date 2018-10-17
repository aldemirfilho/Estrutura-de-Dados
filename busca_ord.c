#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//////////////////////////////////////////////////////

/////////////--------Buscas--------///////////////////

//////////////////////////////////////////////////////

int buscalinear(int *v, int size, int elemento)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (v[i] == elemento)
		{
			return i;
		}
	}
}

int buscalinearrecu(int *v, int size, int indice, int elemento)
{
	if(v[indice] == elemento)
		return indice;
	if (indice == size - 1)
		return -1;
	else
	{
		buscalinearrecu(&v[0], size, indice + 1, elemento);
	}
}

int buscabin(int *v, int size, int elemento)
{
	int inicio = 0;
	int final = size - 1;
	int meio;
	while(inicio <= final)
	{
		meio = (inicio + final) / 2;
		if(v[meio] > elemento)
			final = meio - 1;
		if(v[meio] < elemento)
			inicio = meio + 1;
		else
			return meio;
	}
	return -1;
}

int buscabinrecu(int *v, int inicio, int final, int elemento)
{
	int meio;
	meio = (inicio + final) / 2;
	if(inicio > final)
		return -1;
	else 
	{
		if(elemento > v[meio])
			buscabinrecu(&v[0], meio + 1, final, elemento);
		else if(elemento < v[meio])
			buscabinrecu(&v[0], inicio, meio - 1, elemento);
		else 
			return meio;
	}
}

//////////////////////////////////////////////////////

//////////////--------Sorts--------///////////////////

//////////////////////////////////////////////////////

void swap(int *x, int *y){ 
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

void selection_sort(int *v, int size)
{
	int i, j, min, aux;
	for(i = 0; i < size; i++)
	{
		min = i;
		for(j = i + 1; j < size; j++)
		{
			if(v[j] < v[min])
				min = j;
		}
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}
}

void bubble_sort(int *v, int size)
{
	int i, j, aux;
	for(i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (v[j] < v[i])
			{
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
			}
		}
	}
}

void quick_sort(int *a, int left, int right) 
{
    int i, j, pivo, aux; 
    i = left;
    j = right;
    pivo = a[(left + right) / 2]; 
    while(i <= j) 
    {
        while(a[i] < pivo && i < right)
        {
            i++;
        }
        while(a[j] > pivo && j > left)
        {
            j--;
        }
        if(i <= j) 
        {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
        }
    }  
    if(j > left) 
    {
        quick_sort(a, left, j);
    }
    if(i < right)
    {
        quick_sort(a, i, right);
    }
}

void insertion_sort(int *v, int size)
{
	int i, j, key;
	for(i = 1; i < size; i++)
	{
		key = v[i];
		j = i - 1;
		while ( j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}
}

void merge(int *v, int esq, int meio, int dir)
{
	//printf("sss %d %d %d\n", esq, meio, dir);
	int n1 = meio - esq + 1;
	//printf("n1 %d\n", n1);
	int n2 = dir - meio;
	//printf("n2 %d\n", n1);
	int i, j, k, l[n1 + 1], r[n2 + 1];

	for(i = 1; i <= n1; i++)
	{
		//printf("hahhh\n");
		l[i] = v[esq + i - 1];
	}
	for(j = 1; j <= n2; j++)
	{
		r[j] = v[meio + j];
	}

	l[n1 + 1] = INT_MAX;
	r[n2 + 1] = INT_MAX;

	i = 1; j = 1;

	for (k = esq; k <= dir; k++)
	{
		if (l[i] <= r[j])
		{
			v[k] = l[i];
			i++;
		}
		else
		{
			v[k] = r[j];
			j++;
		}
	}
}

void merge_sort(int *v, int esq, int dir)
{
	//printf("inicio %d %d\n", esq, dir);
	int meio;
	if (esq < dir)
	{
		meio = (esq + dir) / 2;
		merge_sort(v, esq, meio);
		merge_sort(v, meio + 1, dir);
		//printf("### %d %d %d\n", esq, meio, dir);
		merge(v, esq, meio, dir);
	}
}

int main()
{
	int i, n, op, modo, numero, sort;
	printf("Digite 1 para reaizar uma busca ou 2 para uma ordenação!\n");
	scanf("%d", &op);
	printf("Digite o tamanho do array.\n");
	scanf("%d", &n);
	int a[n];
	printf("Digite os elementos do array\n");
	for (i = 0; i < n; i++)
	{			
		scanf("%d", &a[i]);
	}
	if (op == 1)
	{
		printf("Digite o elemento a ser procurado\n");
		scanf("%d", &numero);
		printf("Digite 1 para busca linear, 2 para busca linear recursiva, 3 para busca binaria ou 4 para busca binaria recursiva\n");
		scanf("%d", &modo);
		
		if (modo == 1)
		{
			printf("Posicao ---> [%d]\n", buscalinear(&a[0], n, numero));
		}
		
		if (modo == 2)
		{
			printf("Posicao ---> [%d]\n", buscalinearrecu(&a[0], n, 0, numero));
		}

		if (modo == 3)
		{
			printf("Posicao ---> [%d]\n", buscabin(&a[0], n, numero));
		}

		if (modo == 4)
		{
			printf("Posicao ---> [%d]\n", buscabinrecu(&a[0], 0, n - 1, numero));
		}
	}
	else if (op == 2)
	{
		printf("Qual sort deseja usar, digite: 1) selection sort, 2) bubble sort, 3) Quick sort, 4) insertion sort, 5) merge sort\n");
		scanf("%d", &sort);

		if(sort == 1)
		{
			selection_sort(&a[0], n);
			for(i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n");
		}

		if(sort == 2)
		{
			bubble_sort(&a[0], n);
			for(i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n");
		}

		if(sort == 3)
		{
			quick_sort(&a[0], 0, n - 1);
			for(i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n");
		}

		if(sort == 4)
		{
			insertion_sort(&a[0], n);
			for(i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n");
		}

		if(sort == 5)
		{
			merge_sort(&a[0], 0, n - 1);
			for(i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n");
		}

	}
	return 0;
}