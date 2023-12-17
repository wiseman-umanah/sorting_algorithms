#include "sort.h"

/**
 * swap - swaps the value of teo numbers
 * @num1: first number
 * @num2: second number
*/

void swap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * partition - handles the left and the right boundof array
 * @arr: the array
 * @lb: the left bound
 * @rb: the right bound
 * Return: returns the swapped index
*/

int partition(int *arr, int lb, int rb)
{
	int pivot, i, j;
	
	pivot = arr[rb];
	i = j = lb;

	for (j = lb; j < rb; ++j)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			++i;
		}
	}
	swap(&arr[i], &arr[rb]);
	return (i);
}

/**
 * sort - effectively handles the sorting
 * using the Lumto partition scheme
 * @arr: the array
 * @l: beginning of array usually 0
 * @r: end of array
 * @size: the size of the array for printing purpose
*/

void sort(int *arr, int l, int r, size_t size)
{
	int i;
	if (l >= r)
		return;
	i = partition(arr, l, r);

	print_array(arr, size);
	sort(arr, l, i - 1, size);
	sort(arr, i + 1, r, size);
}

/**
 * quick_sort - dummy function to move to main sort function
 * @array: the array to be sorted
 * @size: the size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	sort(array, 0, size - 1, size);
}
