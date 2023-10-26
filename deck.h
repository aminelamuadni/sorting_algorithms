#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Enumeration of card kinds (suits)
 *
 * @SPADE: Value representing the spade suit
 * @HEART: Value representing the heart suit
 * @CLUB: Value representing the club suit
 * @DIAMOND: Value representing the diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card
 *
 * @value: A pointer to a string representing the value of the card.
 *         It can be values ranging from "Ace" to "King".
 * @kind: Kind of the card (suit). It is an enumerated value from kind_t.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node representing a card in a doubly-linked list deck.
 *
 * @card: Pointer to the card structure representing the playing card.
 * @prev: Pointer to the previous node in the doubly-linked list.
 * @next: Pointer to the next node in the doubly-linked list.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

int card_value(const char *str);
int node_cmp(deck_node_t *a, deck_node_t *b);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
