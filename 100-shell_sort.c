#include "sort.h"

/**
 * shell_sort - function to sort an array using shell sort algorithm
 *
 * @array: array to sort
 * @size: size of aray to sort
 *
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	int n = 0, m = 0, i = 0, prev, n_const;

	while (m < (int)size)
	{
		n = (n * 3) + 1;
		m = (n * 3) + 1;
	}

	while (n != 0)
	{
		n_const = n;
		while (n_const <= (int)size - 1)
		{
			if (array[i] > array[n_const])
			{
				swap_elements(array, i, n_const);
				prev = i;
				while ((prev - n >= 0) && array[prev - n] > array[prev])
				{
					swap_elements(array, prev - n, prev);
					prev = prev - n;
				}
			}
			i++;
			n_const++;
		}
		n = (n - 1) / 3;
		i = 0;
		print_array(array, size);
	}
}

/**
 * swap_elements - function to swap two integers in an array
 *
 * @array: array to swap from
 * @i: index of first element to swap
 * @j: index of second element to swap
 *
 * Return: nothing
 */
void swap_elements(int *array, size_t i, size_t j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
