#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sort doubly linked list int in asc order
 * @list: the list to sort
 *
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;
		while (current->prev != NULL && current->n < (current->prev)->n)
			{
			(current->prev)->next = current->next;

			if (current->next != NULL)
			(current->next)->prev = current->prev;

			current->next = current->prev;
			current->prev = (current->prev)->prev;
			(current->next)->prev = current;

			if (current->prev == NULL)
			*list = current;
			else
			(current->prev)->next = current;
			print_list(*list);
			}
		current = temp;
	}
}
