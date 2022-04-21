#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the address of the first node
 * @str: the value of the str field of the new node
 *
 * Return: head of the new list. Otherwise NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *trav, *new;

	if (head == NULL)
		return (NULL);

	trav = *head;

	/* create the new node */
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = (str == NULL) ? "(nil)" : strdup(str);
	new->len = (str == NULL) ? 0 : _strlen(str);
	new->next = NULL;

	/* if the list has no elements */
	if (trav == NULL)
	{
		*head = new;
		return (*head);
	}

	/* traverse to the end of the list */
	while (trav->next != NULL)
		trav = trav->next;

	trav->next = new;

	return (*head);
}

/**
 * _strlen - finds the length of a given string
 * @str: given string
 *
 * Return: length of str
 */
unsigned int _strlen(const char *str)
{
	unsigned int length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}
