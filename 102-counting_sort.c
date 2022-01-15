#include "sort.h"

/**
 * counting_sort - function to sort an array using the counting sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array to be sorted
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0], i = 0;
	int *element_count;
	int *final_array;

	if (size == 0 || array == NULL)
		return;
	if (size > 1)
	{
		while (i < (int)size)
		{
			if (array[i] > max)
				max = array[i];
			i++;
		}
		element_count = malloc((max + 1) * sizeof(int));
		final_array = malloc((size - 1) * sizeof(int));
		for (i = 0; i < max; i++)
			element_count[i] = 0;
		for (i = 0; i < (int)size; i++)
			element_count[array[i]]++;
		for (i = 0; i <= max; i++)
			element_count[i] += element_count[i - 1];
		print_array(element_count, max + 1);
		for (i = (int)size - 1; i >= 0; i--)
		{
			final_array[element_count[array[i]] - 1] = array[i];
			element_count[array[i]]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = final_array[i];
		free(element_count);
		free(final_array);
	}
}
