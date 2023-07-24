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
	listint_t *current, *next, *tmp_1, *tmp_2, *sorted = NULL;

	if (list == NULL)
		return;

	current = (*list);
	while (current != NULL)
	{
		next = current->next;

		if (sorted == NULL || sorted->n > current->n)
		{
			current->next = sorted;
			sorted = current;
		}
		else
		{
			tmp_1 = sorted;

			while (tmp_1->next != NULL && current->n >= tmp_1->next->n)
				tmp_1 = tmp_1->next;

			if (tmp_1->next == NULL)
			{
				tmp_1->next = current;
				current->prev = tmp_1;
				current->next = NULL;
			}
			else
			{
				tmp_2 = tmp_1->next;
				tmp_1->next = current;
				current->prev = tmp_1;
				current->next = tmp_2;
				tmp_2->prev = current;
				print_list(*list);
			}
		}
		current = next;
		print_list(current);
	}

	(*list) = sorted;
}
