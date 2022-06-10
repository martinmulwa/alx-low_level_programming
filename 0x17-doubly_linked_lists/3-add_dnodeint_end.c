#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the pointer to the 1st node in the list
 * @n: value of new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *trav;

	if (head == NULL)
		return (NULL);

	/* create new node */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	/* navigate to the last node in the list */
	trav = *head;
	while (trav && trav->next)
		trav = trav->next;

	if (trav) /* the list is not empty */
	{
		trav->next = new;
		new->prev = trav;
	}
	else
	{
		*head = new;
	}

	return (new);
}
