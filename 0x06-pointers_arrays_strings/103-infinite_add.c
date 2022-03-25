#include "main.h"
#include <stdio.h>

int _strlen(char *s);

/**
* infinite_add - adds two numbers given as strings
* @n1: first number as a string
* @n2: second number as a string
* @r: the buffer that the function will use to store the result
* @size_r: the buffer size
*
* Return: a pointer to the result
* If the result can not be stored in r the function must return 0
*/
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	/* get the lengths of the strings */
	int len_n1 = _strlen(n1);
	int len_n2 = _strlen(n2);

	int total = 0;
	int rem = 0;
	int i, j, k, l, tmp;

	for (i = len_n1 - 1, j = len_n2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
	{
		if (j < 0)
			total = (n1[i] - '0') + rem;
		else if (i < 0)
			total = (n2[j] - '0') + rem;
		else
			total = (n1[i] - '0') + (n2[j] - '0') + rem;

		rem = total / 10;
		total = total % 10;

		if (k < (size_r - 1))
			r[k] = total + '0';
		else
			return (0);
	}

	/* add any remainders */
	if (rem)
	{
		if (k < (size_r - 1))
			r[k] = rem + '0';
		else
			return (0);
	}

	/* reverse r */
	for (l = 0; l < ((k + 1) / 2); l++)
	{
		tmp = r[l];
		r[l] = r[k - l];
		r[k - l] = tmp;
	}

	/* terminate r */
	r[k + 1] = '\0';

	return (r);
}

/**
 * _strlen - finds the length of a string
 * @s: address of first character in the string
 *
 * Return: length og the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}
