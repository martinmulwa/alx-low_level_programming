#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to the pointer to the first node
 *
 * Return: the head node’s data (n). Otherwise 0
 */
int pop_listint(listint_t **head)
{
	listint_t *current;
	int val = 0;

	if (head == NULL || *head == NULL)
		return (0);

	current = *head;
	val = current->n;
	*head = current->next;

	free(current);

	return (val);
}
