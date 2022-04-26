#include "lists.h"

/**
 * get_nodeint_at_index - finds the nth node of a listint_t linked list
 * @head: pointer to the 1st node in the list
 * @index: the index of the node, starting at 0
 *
 * Return: the nth node of the list. Otherwise NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	while (i < index && head != NULL)
	{
		head = head->next;
		i++;
	}

	return (head);
}
