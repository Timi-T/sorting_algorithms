#include "sort.h"

/**
 * bubble_sort - function to sort an array using bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array to be sorted
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int sorted = 1;
	size_t actual_size = size;

	if (size > 1)
	{
		while (i != (size - 1))
		{
			if (array[i] > array[i + 1])
			{
				sorted += 1;
				swap(array, i);
				print_array(array, actual_size);
			}
			i++;
			if (i == (size - 1))
			{
				if (sorted == 1)
					break;
				size--;
				i = 0;
				sorted = 1;
			}
		}
	}
}

/**
 * swap - function to swap two consecutive elements of an array
 *
 * @array: array to be swapped from
 * @i: element index to swap
 *
 * Return: nothing
 */
void swap(int *array, int i)
{
	int temp;

	temp = array[i];
	array[i] = array[i + 1];
	array[i + 1] = temp;
}
