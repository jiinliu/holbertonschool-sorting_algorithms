#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps a node with its previous node in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @node: The node to swap with its previous node.
 */
static void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev;

	prev = node->prev;
	if (prev->prev != NULL)
	{
		prev->prev->next = node;
	}
	else
	{
		*list = node;
	}
	node->prev = prev->prev;
	prev->prev = node;
	prev->next = node->next;
	if (node->next != NULL)
	{
		node->next->prev = prev;
	}
	node->next = prev;
}

/**
 * insertion_sort_list - function
 *                       using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description: After each swap of two nodes, the list is printed.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current);
			print_list(*list);
		}
		current = next;
	}
}
