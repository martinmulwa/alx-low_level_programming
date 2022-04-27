#include "lists.h"

/**
 * reverse_listint -  reverses a listint_t linked list
 * @head: a pointer to the pointer to the first node in the list
 *
 * Return: a pointer to the first node of the reversed list. Otherwise NULL
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next = NULL;
	listint_t *prev = NULL;

	if (head == NULL)
		return (NULL);

	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}
