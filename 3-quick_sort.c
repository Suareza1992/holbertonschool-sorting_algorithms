#include "sort.h"

/**
 * quick_sort - will sort an array of integers in ascending order
 *
 * @array: array of inetegrs to sort
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;

	sort_helper(array, 0, size - 1, size);
}

/**
 * sort_helper - helper function for quick sort
 * @array: array of integers to sort
 * @low: integer being compared
 * @high: integer being compared
 * @size: size of array
 */

void sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		sort_helper(array, low, pivot - 1, size);
		sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * partition - helper function for quick sort
 * @array: array of inetegrs to sort
 * @low: integer being compared
 * @high: integer being compared
 * @size: size of the array
 * Return: pivot index
*/

int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
