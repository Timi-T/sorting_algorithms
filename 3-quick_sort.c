#include "sort.h"

/**
 * quick_sort - function to sort an array using the quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array to be sorted
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	int lb = 0;
	int ub = (int)size - 1;

	if (size > 1)
		start_sort(array, lb, ub, size);
}

/**
 * start_sort - recursive function to start sorting array
 *
 * @array: partition of array to be sorted
 * @lb: lower bound of array partition
 * @ub: upper bound of array partition
 * @size: size of array
 *
 * Return: nothing
 */
void start_sort(int *array, int lb, int ub, size_t size)
{
	int pivot_index;

	if (lb < ub)
	{
		pivot_index = partition(array, lb, ub, size);
		start_sort(array, lb, (pivot_index - 1), size);
		start_sort(array, (pivot_index + 1), ub, size);
	}
}

/**
 * partition - function to partition an array using a pivot
 *
 * @array: array to partition
 * @start: starting point of array
 * @end: end point of array
 * @size: size of array
 *
 * Return: pivot index
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot_index = end;
	int pivot = array[pivot_index];

	while (start <= end)
	{
		while (array[start] < pivot)
			start++;
		while (array[end] >= pivot)
			end--;
		if (end > start)
		{
			swap_elements(array, start, end);
			print_array(array, size);
		}
	}
	if (start != pivot_index)
	{
		swap_elements(array, start, pivot_index);
		print_array(array, size);
	}
	return (start);
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
