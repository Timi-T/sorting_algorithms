#include "deck.h"

/**
 * sort_deck - function to sort a deck of cards
 *
 * @deck: head node of deck
 *
 * Return: nothing
 */
void sort_deck(deck_node_t **deck)
{
        deck_node_t *deck_copy = *deck;
        if (deck_copy && deck_copy->next)
        {
                insert_sort_deck_values(deck);
                insert_sort_deck_kind(deck);
        }
}

/**
 * insert_sort_deck_values - function to sort all values of the deck
 *
 * @deck: deck of cards as a linked list
 *
 * Return: nothing
 */
void insert_sort_deck_values(deck_node_t **deck)
{
        deck_node_t *new_deck = *deck;
        deck_node_t *back_trk;
        int value_1, value_2;

        while (new_deck)
        {
                value_1 = get_value(new_deck);
                value_2 = get_value(new_deck->next);
                if ((new_deck->next) && value_1 > value_2)
                {
                        if (new_deck->prev == NULL)
                                *deck = new_deck->next;
                        forward_swap_nodes(new_deck);
                        back_trk = new_deck->prev;
                        value_1 = get_value(back_trk->prev);
                        value_2 = get_value(back_trk);
                        while ((back_trk->prev) && value_1 > value_2)
                        {
                                if (!(back_trk->prev)->prev)
                                        *deck = back_trk;
                                forward_swap_nodes(back_trk->prev);
                                value_1 = get_value(back_trk->prev);
                                value_2 = get_value(back_trk);
                        }
                }
                else
                        new_deck = new_deck->next;
        }
}

/**
 * insert_sort_deck_kind - function to sort all kinds of the deck
 *
 * @deck: deck of cards as a linked list
 *
 * Return: nothing
 */
void insert_sort_deck_kind(deck_node_t **deck)
{
        deck_node_t *new_deck = *deck;
        deck_node_t *back_trk;
        int value_1;
        int value_2;

        while(new_deck)
        {
                value_1 = (new_deck->card)->kind;
                if (new_deck->next)
                        value_2 = ((new_deck->next)->card)->kind;
                else
                        break;
                if ((new_deck->next) && value_1 > value_2)
                {
                        if (new_deck->prev == NULL)
                                *deck = new_deck->next;
                        forward_swap_nodes(new_deck);
			back_trk = new_deck->prev;
                        value_2 = (back_trk->card)->kind;
                        while ((back_trk->prev) &&
                                        ((back_trk->prev)->card)->kind
                                        > (back_trk->card)->kind)
                        {
                                if (!(back_trk->prev)->prev)
                                        *deck = back_trk;
                                forward_swap_nodes(back_trk->prev);
                        }
                }
                else
                        new_deck = new_deck->next;
        }
}

/**
 * get_value - function to get the corresponding integer of values
 *
 * @deck_node: deck node to get integer value of
 *
 * Return: the integer value of the node
 */
int get_value(deck_node_t *deck_node)
{
        const char *card_name;
        int value;

        if (deck_node == NULL)
                return (-1);
        card_name = (deck_node->card)->value;
        if (card_name[0] == 'J')
                value = 11;
        else if (card_name[0] == 'Q')
                value = 12;
        else if (card_name[0] == 'K')
                value = 13;
        else if (card_name[0] == 'A')
                value = 0;
        else if (strlen(card_name) == 2)
                value = 10;
	else
                value = (int)card_name[0] - 48;
        return (value);
}

/**
 * forward_swap_nodes - function to swap 2 consecutive nodes
 *
 * @deck_node: the preceding node to be swapped
 *
 * Return: nothing
 */
void forward_swap_nodes(deck_node_t *deck_node)
{
        deck_node_t *current_node;
        deck_node_t *next_node;
        deck_node_t *temp1;
        deck_node_t *temp2;

        current_node = deck_node;
        next_node = deck_node->next;
        temp1 = deck_node->prev;
        temp2 = next_node->next;
        current_node->next = temp2;
        current_node->prev = next_node;
        if (temp2)
                temp2->prev = current_node;
        next_node->next = current_node;
        next_node->prev = temp1;
        if (temp1)
                temp1->next = next_node;
}
