#include "sort.h"

/**
 * bubble_sort - for sorting an array of defined size
 *
 * @array: the array to be sorted
 * @size: the defined size of the array for convenience sorting
 * Return : nothing, a void function
*/
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, t = size;
	/**
	*for (i = 0; i < size; i++)
	*{
	*	for (j = i; j, j < size; j++)
	*	{
	*		if (array[i] > array[j])
	*		{
	*			temp = array[j];
	*			array[j] = array[i];
	*			array[i] = temp;
	*			print_array(array, size);
	*		}
	*	}
	*} #this also works like bubble sort but seems a little bit faster
	*/
	if (t < 2)
		return;
	for (i = 0; i < t - 1; i++)
	{
		for (j = 0; j < t - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
