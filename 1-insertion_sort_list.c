/*
*#include "sort.h"
*#include <stdio.h>
* This was a second implementation of the function
* it might fail in most cases
*listint_t *reverse_list(listint_t **head);
* void insertion_sort_list(listint_t **list)
*{
*	listint_t *start, *current, *temp;
*
*	start = *list;
*	current = start->next;
*	while (current != NULL)
*	{
*		if (current->n > start->n)
*			start = current;
*		else
*		{
*			temp = start;
*			while (temp != NULL)
*			{
*				if (temp->n > current->n)
*				{
*					if (temp->prev == NULL)
*					{
*						temp->prev = current;
*						current->prev = NULL;
*						temp->next = current->next;
*						(current->next)->prev = temp;
*						current->next = temp;
*					}
*					else
*					{
*						(temp->prev)->next = current;
*						current->prev = temp->prev;
*						temp->next = current->next;
*						current->next = temp;
*						temp->prev = current;
*					}
*					print_list(reverse_list(list));
*				}
*				temp = temp->prev;
*			}
*		}
*		current = start->next;
*	}
*}

*listint_t *reverse_list(listint_t **head)
*{
*	while ((*head)->prev != NULL)
*		*head = (*head)->prev;
*	return (*head);
}
*/




#include "sort.h"
#include <stdio.h>


/**
 * insertion_sort_list - Sorts a doubly linked list
 * using the insertion sort algorithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			current->next->prev = current;

			print_list(*list);
		}

		current = temp;
	}
}
