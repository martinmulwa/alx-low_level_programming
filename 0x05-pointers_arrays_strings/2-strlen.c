#include "main.h"

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
