#include "sort.h"

/**
 * selection_sort - will sort an  array of inetgers in ascending order
 * @array: array of inetegrs to sort
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		size_t lowest = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[lowest])
			{
				lowest = j;
			}
		}

		if (lowest != i)
		{
			swap_ints(&array[i], &array[lowest]);
			print_array(array, size);
		}
	}
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
