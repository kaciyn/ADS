# include <stdio .h>
# define MAX 5

void display(int *);
void init(int *);
void insert(int *, int pos, int num);
void delete (int *, int pos);
void reverse(int *);
void search(int *, int num);

int main(void)
{
	int array[MAX];
	display(array);
	return 0;
}

void display(int *array)
{
	int index;
	for (index = 0; index < MAX; index++)
	{
		printf("%d\t", index);
	}
	printf("\n");

	for (index = 0; index < MAX; index++)
	{
		printf("%d\t", array[index]);
	}
	printf("\n");
}

void init(int *array)
{
	int index;
	for (index = 0; index < MAX; index++)
	{
		array[index] = 0;
	}
}

void insert(int *array, int pos, int num)
{
	int index;

	for (index = MAX - 1; index >= pos; index--)
	{
		array[index] = array[index - 1];
	}
	array[index] = num;
}

void delete (int *array, int pos)
{
	int index;
	for (index = pos; index < MAX; index++)
	{
		array[index - 1] = array[index];
	}
	array[index - 1] = 0;
}

void reverse(int *array)
{
	int idx;
	for (idx = 0; idx < MAX / 2; idx++)
	{
		int temp = array[idx];
		array[idx] = array[MAX - 1 - idx];
		array[MAX - 1 - idx] = temp;
	}
}

void search(int *array, int num)
{
	int idx;
	for (idx = 0; idx < MAX; idx++)
	{
		if (array[idx] == num)
		{
			printf("%d found in position %d\n", num, idx + 1);
			return;
		}
	}
	if (idx == MAX)
		printf("%d not found in array \n", num);
}

void expand(int *array, )