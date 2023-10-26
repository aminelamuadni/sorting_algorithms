#include "deck.h"
#include <string.h>

/**
 * card_value - get the value of the card in int
 * @str: card value as string
 * Return: int representation of card
 */
int card_value(const char *str)
{
	if (!strcmp(str, "Ace"))
		return (1);
	if (!strcmp(str, "Jack"))
		return (11);
	if (!strcmp(str, "Queen"))
		return (12);
	if (!strcmp(str, "King"))
		return (13);
	return (atoi(str));
}

/**
 * node_cmp - compare two nodes of a deck
 * @a: first node
 * @b: second node
 * Return: negative if a < b, 0 if equal, positive if a > b
 */
int node_cmp(deck_node_t *a, deck_node_t *b)
{
	int val_cmp;

	if (a->card->kind > b->card->kind)
		return (1);
	if (a->card->kind < b->card->kind)
		return (-1);

	val_cmp = card_value(a->card->value) - card_value(b->card->value);
	return (val_cmp);
}

/**
 * sort_deck - sort a deck of cards
 * @deck: pointer to a deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *tmp;

	if (!deck || !*deck || !(*deck)->next)
		return;

	current = (*deck)->next;

	while (current)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev && node_cmp(tmp, tmp->prev) < 0)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;

			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*deck = tmp;
		}
	}
}
