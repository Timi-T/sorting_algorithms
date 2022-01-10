#include "sort.h"

/**
 * insertion_sort_list - function to sort an array using bubble sort algorithm
 *
 * @list: linked list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *list_cp = *list;
	listint_t *new_list = list_cp;
	listint_t *back_trk;

	if (new_list && new_list->next)
	{
		while (new_list)
		{
			if ((new_list->next) && ((new_list)->n > (new_list->next)->n))
			{
				forward_swap_nodes(new_list);
				print_list(*list);
				back_trk = new_list->prev;
				while ((back_trk->prev) && ((back_trk->prev)->n
						> (back_trk)->n))
				{
					forward_swap_nodes(back_trk->prev);
					if (!(back_trk->prev))
						*list = back_trk;
					print_list(*list);
				}
			}
			else
				new_list = new_list->next;
		}
	}
}

/**
 * forward_swap_nodes - function to swap two consective nodes
 *
 * @list: node to be swapped from list
 *
 * Return: nothing
 */
void forward_swap_nodes(listint_t *list)
{
	listint_t *current_node;
	listint_t *next_node;
	listint_t *temp1;
	listint_t *temp2;

	current_node = list;
	next_node = list->next;
	temp1 = list->prev;
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
