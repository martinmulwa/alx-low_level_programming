#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the pointer to the 1st node in the list
 * @idx: position to insert new node
 * @n: data value of new node
 *
 * Return: address of new node. Otherwise NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *new;

	if (h == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t)); /* create new node */
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (idx == 0) /* add the new node to the beginning of the list */
	{
		new->next = *h;
		*h = new;
		return (new);
	}

	/* go to the node just before position to insert */
	current = *h;
	while (current && --idx)
		current = current->next;

	if (current)
	{
		new->next = current->next;
		if (new->next)
			new->next->prev = new;

		new->prev = current;
		current->next = new;
		return (new);
	}

	return (NULL);
}
