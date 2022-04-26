#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the first node
 *
 * Return: number of elements in the linked list
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	const listint_t *trav;

	for (trav = h; trav; trav = trav->next, count++)
		printf("%d\n", trav->n);

	return (count);
}
