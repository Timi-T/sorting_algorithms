#include "sort.h"

/**
 * cocktail_sort_list - function to sort an array using bubble sort algorithm
 *
 * @list: list to be sorted
 *
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	int sorted = 1;
	listint_t *new_list = *list, *prev;

	while (new_list->next != NULL)
	{
		if ((new_list->next) && (new_list->n > (new_list->next)->n))
		{
			sorted += 1;
			forward_swap_nodes(new_list);
			if ((new_list->prev)->prev == NULL)
				*list = new_list->prev;
			print_list(*list);
		}
		else
			new_list = new_list->next;
		if (new_list->next == NULL)
		{
			if (sorted == 1)
				break;
			while (new_list->prev != NULL)
			{
				sorted = 1;
				if (new_list->prev &&
				(new_list->prev)->n > new_list->n)
				{
					sorted += 1;
					prev = new_list->prev;
					forward_swap_nodes(prev);
					if (new_list->prev == NULL)
						*list = new_list;
					print_list(*list);
				}
				else
					new_list = new_list->prev;
			}
			if (sorted == 1)
				break;
			sorted = 1;
		}
	}
}

/**
 * forward_swap_nodes - function to swap 2 consecutive nodes of a linked list
 *
 * @list: node to be swapped
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
