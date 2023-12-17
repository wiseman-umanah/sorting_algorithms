#include "sort.h"
#include <stdio.h>

/**
* selection_sort - This is a code shows how
* selection sort algorithm works
* @array: The array to implement on
* @size: The size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min, tmp;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
		if (min != i)
			print_array(array, size);
	}
}
