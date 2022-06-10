#include "lists.h"

/**
 * get_dnodeint_at_index - finds the nth node of a dlistint_t linked list
 * @head: pointer to the first node in the list
 * @index: index of node
 *
 * Return: address of node if found. Otherwise NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (head && index)
	{
		index--;
		head = head->next;
	}

	return (head);
}
