#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - implemetation of buble sort
 *
 * @array: pointer to an int array
 * @size: size of int array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, new_size, is_sorted;

	if (size < 2 || size <= 0 || array == NULL)
		return;

	while (1)
	{
		is_sorted = 0;
		new_size = size - 1;

		for (x = 0; x < new_size; x++)
		{
			/** swap values if this condition is True */
			if (array[x] > array[x + 1])
			{
				int tmp = array[x];

				array[x] = array[x + 1];
				array[x + 1] = tmp;
				print_array(array, size);
				is_sorted = 1;
			}
		}

		if (is_sorted == 0)
			break;
	}
}
