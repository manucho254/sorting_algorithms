#include "sort.h"
#include <stddef.h>

/**
 * swap - function to swap two values.
 *
 * @a: pointer to integer a.
 * @b: pointer to integer b.
 */

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - selction sort algorithim
 *
 * @array: pointer to integer array.
 * @size: size of integer array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t x, i, selected;

	for (x = 0; x < size - 1; x++)
	{
		selected = x; /** index for the selected value*/
		for (i = x + 1; i < size; i++)
		{
			/**
			 * check if value at array[i],
			 * is less that value at array[selected],
			 * if condtion is true update the selected index.
			 */
			if (array[i] < array[selected])
				selected = i;
		}
		/** swap value if selected not equal to x */
		if (selected != x)
		{
			swap(&array[selected], &array[x]);
			print_array(array, size);
		}
	}
}
