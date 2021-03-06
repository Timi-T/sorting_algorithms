#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <string.h>

/**
 * enum kind_e - enumeration of shapes
 * @SPADE: enum to 0
 * @HEART: enum to 1
 * @CLUB: enum to 2
 * @DIAMOND: enum to 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
void insert_sort_deck_values(deck_node_t **deck);
int get_value(deck_node_t *deck_node);
void forward_swap_nodes(deck_node_t *deck_node);
void insert_sort_deck_kind(deck_node_t **deck);

#endif
