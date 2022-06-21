#include <stdio.h>
#include <stdlib.h>
#define TOTAL_SIZE 30 // total size to which array can be extended
typedef struct customArr
{
	int size; // size set by user
	int *arr;
} customArr;

customArr *create()
{
	customArr *a = (customArr *)malloc(sizeof(customArr));
	printf("Enter the size of arr: ");
	scanf("%d", &a->size);
	a->arr = (int *)malloc(sizeof(int) * TOTAL_SIZE);
	return a;
}

int set(customArr *a)
{
	int index, value;
	printf("Enter index and value: ");
	scanf("%d %d", &index, &value);
	if (index >= a->size)
	{
		printf("Invalid\n");
		return 0;
	}
	a->arr[index] = value;
	return 1;
}

int get(customArr *a)
{
	int index;
	printf("Enter the Index: ");
	scanf("%d", &index);
	if (index >= a->size)
	{
		printf("Invalid\n");
		return 0;
	}
	printf("%d: %d\n", index, a->arr[index]);
	return 1;
}

int display(customArr *a)
{
	printf("Displaying: \n");
	for (int i = 0; i < a->size; i++)
	{
		printf("%d: %d\n", i, a->arr[i]);
	}
}

int insert(customArr *a)
{
	int index, value;
	printf("Enter index and value:");
	scanf("%d %d", &index, &value);
	// if index is higher, or array is full
	if (index > a->size || a->size == TOTAL_SIZE)
	{
		printf("Invalid\n");
		return 0;
	}
	(a->size)++;
	for (int i = a->size - 1; i > index; i--)
	{
		a->arr[i] = a->arr[i - 1];
	}
	a->arr[index] = value;
}

int delete (customArr *a)
{
	int index;
	printf("Enter the index: ");
	scanf("%d", &index);
	// if index is higher or array is empty
	if (index >= a->size || a->size == 0)
	{
		printf("Invalid\n");
		return 0;
	}
	(a->size)--;
	for (int i = index; i < a->size; i++)
	{
		a->arr[i] = a->arr[i + 1];
	}
	return 1;
}

int fill(customArr *a)
{
	for (int i = 0; i < a->size; i++)
	{
		printf("Enter value at %d: ", i);
		scanf("%d", &a->arr[i]);
	}
	return 1;
}

int freeArr(customArr *a)
{
	free(a->arr);
	free(a);
	return 1;
}
int main()
{
	customArr *a = create();
	int input;
	while (1)
	{
		printf("--------\n0: set\n1: get\n2: display\n3: fill\n4: insert\n5: delete\n6: free\n7: exit\n--------\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			set(a);
			break;
		case 1:
			get(a);
			break;
		case 2:
			display(a);
			break;
		case 3:
			fill(a);
			break;
		case 4:
			insert(a);
			break;
		case 5:
			delete (a);
			break;
		case 6:
		case 7:
			freeArr(a);
			return 0;
		}
	}
}