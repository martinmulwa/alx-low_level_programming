#include "lists.h"

/**
 * dlistint_len - finds the number of elements in a linked dlistint_t list
 * @h: pointer to the first node in the list
 *
 * Return: number of nodes in given list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
