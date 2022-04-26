#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the first node
 *
 * Return: number of elements in the linked list
 */
size_t print_listint(const listint_t *h)
{
	size_t count;

	for (count = 0; h; h = h->next, count++)
		printf("%d\n", h->n);

	return (count);
}
