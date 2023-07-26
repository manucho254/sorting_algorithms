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
	listint_t *current, *ptr, *tmp;
	int n;

	current = (*list);
	if (current->next == NULL)
		return;

	current = current->next;

	while (current != NULL)
	{
		n = 0;
		ptr = current;
		tmp = current->prev;
		current = current->next;

		while (tmp != NULL && tmp->n > ptr->n)
		{
			n++;
			tmp = tmp->prev;
		}

		if (n)
		{
			ptr->prev->next = ptr->next;
			
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;

			if (tmp == NULL)
			{
				tmp = (*list);
				ptr->prev = NULL;
				ptr->next = tmp;
				ptr->next->prev = ptr;
				(*list) = ptr;
				print_list(*list);
			}
			else
			{
				tmp = tmp->next;
				tmp->prev->next = ptr;
				ptr->prev = tmp->prev;
				tmp->prev = ptr;
				ptr->next = tmp;
				print_list(*list);
			}
		}
	}


}
