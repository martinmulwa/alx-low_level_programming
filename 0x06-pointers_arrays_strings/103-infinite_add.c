#include "main.h"
#include <stdio.h>

int _strlen(char *s);
void rev_string(char *s);

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
	int total, rem = 0;
	int i, j, k;

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
	/* terminate r */
	r[k + 1] = '\0';
	/* reverse r*/
	rev_string(r);

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

/**
 * rev_string -  reverses a given string
 * @s: address of first character in the string
 */
void rev_string(char *s)
{
	/* get the length of the string */
	int length = _strlen(s);
	int i;
	int mir_i;
	char tmp;

	/* swap elements in mirror positions */
	for (i = 0; i < (length / 2); i++)
	{
		/* find the corresponsing mirror index */
		mir_i = length - (i + 1);

		tmp = *(s + i);
		*(s + i) = *(s + mir_i);
		*(s + mir_i) = tmp;
	}
}
