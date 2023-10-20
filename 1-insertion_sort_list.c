#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: double pointer to the beginning of the list
 * @a: node to swap
 * @b: node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the beginning of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current->prev;
		while (temp && temp->n > current->n)
		{
			swap_nodes(list, temp, current);
			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
