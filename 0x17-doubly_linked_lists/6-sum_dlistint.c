#include "lists.h"

/**
 * sum_dlistint - finds the sum of all the data (n) of a dlistint_t linked list
 * @head: pointer to the first node in the list
 *
 * Return: calculated sum. Otherwise 0
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	while (head)
	{
		total += head->n;
		head = head->next;
	}

	return (total);
}
