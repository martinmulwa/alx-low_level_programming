#include "lists.h"

/**
 * listint_len - finds the number of elements in a linked listint_t list
 * @h: pointer to the first node in the list
 *
 * Return: number of elements in the given list
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
