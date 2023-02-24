#include "sort.h"

/**
 * printcheck - print a range
 * @array: the array to print
 * @r1: less range
 * @r2: final range
 * Return: Nothing
 */
void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * _swap - swap two elements in an array
 * @array: the array to change values
 * @i: A index
 * @j: another index
 * @dir: direction of the array
 */
void _swap(int *array, int i, int j, int dir)
{
	int tmp;

	if (dir == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * bitonic_merge - swap the elements to sort
 * @array: the array to sort
 * @low: the low element in the range to sort
 * @size: the size of the range to sort
 * @dir: indicate which half are manage
 * @r_size: the size of all the array
 */
void bitonic_merge(int *array, int low, int size, int dir, const int r_size)
{
	int k = size, i = low;

	if (size > 1)
	{
		k = size/ 2;

		for ( i = low; i < low + k; i++)
			_swap(array, i, i + k, dir);

		bitonic_merge(array, low, k, dir r_size);
		bitonic_merge(array, low + k, k, dir, r_size);
	}
}

/**
 * _sort - segmentate the array
 * @array: the array to sort
 * @low: the lowest element in each range
 * @size: size of the range to sort
 * @dir: indicate which half are manage
 * @r_size: the size of all array
 */
void _sort(int *array, int low, int size, int dir, const int r_size)
{
	int k = size;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP):\n", size, r_size);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, r_size);
		printcheck(array, low, low + k - 1);

		k = size / 2;
		_sort(array, low, k, 1, r_size);

		_sort(array, low + k, k, 0, r_size);

		bitonic_merge(array, low, size, dir, r_size);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, r_size);
			printcheck(array, low, low + 2 * k - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, r_size);
			printcheck(array, low, low + 2 * k - 1);
		}
	}
}

/**
 * bitonic_sort - call the sort function
 * @array: the array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2 || !array)
		return;

	_sort(array, 0, (int)size, up, r_size);
}
