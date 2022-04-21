#include "lists.h"

unsigned int _strlen(const char *str);

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the address of the first node
 * @str: the value of the str firld of the new node
 *
 * Return: head of the new list
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	if (head == NULL)
		return (NULL);

	/* allocate space for the new node */
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	if (str == NULL)
	{
		new->str = strdup("(nil)");
		new->len = 0;
	}
	else
	{
		new->str = strdup(str);
		new->len = _strlen(str);
	}

	new->next = *head;
	*head = new;

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
