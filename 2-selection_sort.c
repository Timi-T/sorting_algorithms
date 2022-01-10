#include "sort.h"

/**
 * selection_sort - function to sort using selection sort algorithm
 *
 * @array: array to sort
 * @size: size of array to sort
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	int *array_copy = array;
	int least, temp, swap = 0;
	size_t i = 0, j = 0, current = 0;

	least = array_copy[j];
	while (j != (size - 1) && size > 1)
	{
		if (least > array_copy[i + 1])
		{
			least = array_copy[i + 1];
			current = i + 1;
			swap = 1;
		}
		i++;
		if (i == (size - 1))
		{
			if (swap == 1)
			{
				temp = array_copy[j];
				array_copy[j] = array_copy[current];
				array_copy[current] = temp;
				print_array(array, size);
			}
			j++;
			least = array_copy[j];
			i = j;
			swap = 0;
		}
	}
}
