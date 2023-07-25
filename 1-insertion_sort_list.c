#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insertion_sort_list - implementation of insertion sort.
 *
 * @list: pointer to doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted = NULL;

	if (list == NULL)
		return;

	current = (*list);
	while (current != NULL)
	{
		(*list) = sorted;
	}
}
