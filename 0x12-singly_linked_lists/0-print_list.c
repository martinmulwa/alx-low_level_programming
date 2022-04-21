#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list in a given format
 * @h: pointer to a list_t
 * If str is NULL, print [0] (nil)
 *
 * Return: number of nodes in given list_t
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}

		count++;
		h = h->next;
	}

	return (count);
}
