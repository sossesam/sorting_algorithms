#include "sort.h"

/**
 * swap_the_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @first_node: A pointer to the 1st node to swap.
 * @n2: The 2nd node to swap.
 */
void swap_the_nodes(listint_t **head, listint_t **first_node, listint_t *n2)
{
	(*first_node)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *first_node;
	n2->prev = (*first_node)->prev;
	n2->next = *first_node;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = n2;
	else
		*head = n2;
	(*first_node)->prev = n2;
	*first_node = n2->prev;
}

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_the_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
