#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the pointer of the 1st node in the list
 * @idx: the index of the list where the new node should be added
 * @n: value of the new node
 *
 * Return: ponter to the new node. Otherwise NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *trav;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	/* create the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	trav = *head;
	while (i != idx - 1 && trav != NULL)
	{
		trav = trav->next;
		i++;
	}

	if (i == idx - 1 && trav != NULL)
	{
		new_node->next = trav->next;
		trav->next = new_node;
		return (new_node);
	}

	return (NULL);
}
