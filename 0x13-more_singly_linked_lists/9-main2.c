#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    print_listint(head);
    printf("-----------------\n");
    insert_nodeint_at_index(&head, 0, 4096);
    print_listint(head);
    free_listint2(&head);
    return (0);
}
