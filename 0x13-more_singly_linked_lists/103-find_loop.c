#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the first node in the list
 *
 * Return: address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	/* if the list is empty or contains a single node then it doesnt loop */
	if (head == NULL || head->next == NULL)
		return (NULL);

	/* move fast twice as fast as slow */
	slow = slow->next;
	fast = fast->next->next;

	while (fast && fast->next)
	{
		/* if fast is equal to slow then there's a loop in the list */
		if (slow == fast)
			break;

		slow = slow->next;
		fast = fast->next->next;
	}

	/* if you have not encountered a loop */
	if (slow != fast)
		return (NULL);

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}
