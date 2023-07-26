#include "sort.h"

/**
 * swap - swap two values
 *
 * @array: pointer to integer array.
 * @a: pointer to value a
 * @b: pointer to value b
 * @size: size of integer array.
 */

void swap(int *array, int *a, int *b, size_t size)
{
	int tmp = *a;

	if (*a == *b)
		return;

	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - Partion values in array
 *
 * @array: pointer to integer array.
 * @high: ending index.
 * @low: start index.
 * @size: size of integer array.
 *
 * Return: pivot index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int j, i, pivot = array[high];

	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, &array[i], &array[j], size);
		}
	}

	/** move the pivot element to correct pivot position*/
	i++;
	swap(array, &array[i], &array[high], size);

	return (i);
}

/**
 * sort - sorting function that runs,
 * recursively until base condition is met.
 *
 * @array: pointer to array.
 * @high: ending index.
 * @low: start index.
 * @size: size of integer array.
 *
 */

void sort(int *array, int low, int high, size_t size)
{
	int p;

	/** ensure indeces are in correct order */
	if (low >= high || low < 0)
		return;

	/** partition array and get the pivot index */
	p = lomuto_partition(array, low, high, size);

	sort(array, low, p - 1, size); /** Left side pivot */
	sort(array, p + 1, high, size); /** Left side pivot */
}

/**
 * quick_sort - quick sort algorithm
 *
 * @array: pointer to integer array.
 * @size: size of integer array.
 *
 */

void quick_sort(int *array, size_t size)
{
	int high = size;

	sort(array, 0, high - 1, size); /** sort array */
}
