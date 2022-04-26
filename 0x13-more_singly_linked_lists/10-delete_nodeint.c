#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a linked list
 * @head: pointer to the pointer of the 1st node in the list
 * @index: the index of the node that should be deleted
 *
 * Return: 1 is successful. Otherwise -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev, *tmp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		prev = *head;
		*head = (*head)->next;
		free(prev);
		return (1);
	}

	prev = *head;
	while (i != index - 1 && prev->next != NULL)
	{
		prev = prev->next;
		i++;
	}

	if (i == index - 1 && prev->next != NULL)
	{
		tmp = prev->next;
		prev->next = tmp->next;
		free(tmp);
		return (1);
	}

	return (-1);
}
