#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index
 * of a dlistint_t linked list
 * @head: pointer to the pointer to the 1st node in the list
 * @index: index of node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *trav, *tmp;

	if (head == NULL || *head == NULL)
		return (-1);

	/* delete 1st node */
	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;

		free(tmp);
		return (1);
	}

	trav = *head;
	while (trav && index--)
		trav = trav->next;

	if (trav)
	{
		trav->prev->next = trav->next;
		if (trav->next)
			trav->next->prev = trav->prev;

		free(trav);
		return (1);
	}

	return (-1);
}
