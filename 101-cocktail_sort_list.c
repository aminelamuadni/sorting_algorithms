#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers using
 * the Cocktail shaker sort algorithm.
 * @list: Double pointer to the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *left, *right;

	if (!list || !*list || !(*list)->next)
		return;

	left = *list;
	right = NULL;

	while (swapped)
	{
		swapped = 0;

		for (; left->next != right; left = left->next)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				swapped = 1;
				left = left->prev;
			}
		}
		right = left;
		if (!swapped)
			break;

		swapped = 0;

		for (; left->prev != NULL; left = left->prev)
		{
			if (left->n < left->prev->n)
			{
				swap_nodes(list, left->prev, left);
				swapped = 1;
				left = left->next;
			}
		}
	}
}
