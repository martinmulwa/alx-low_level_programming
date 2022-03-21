#include "main.h"

int _strlen(char *s);

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

/**
 * _strlen - finds the length of a string
 * @s: address of first character in the string
 *
 * Return: length of the string
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
