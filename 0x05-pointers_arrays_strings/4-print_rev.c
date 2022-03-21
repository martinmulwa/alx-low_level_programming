#include "main.h"

void print_rev_rec(char *s);

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: address of first character in the string
 */
void print_rev(char *s)
{
	/* print the reverse string recursively */
	print_rev_rec(s);

	_putchar('\n');
}

/**
 * print_rev_rec - prints a string, in reverse, recursively
 * @s: address of first character in the string
 */
void print_rev_rec(char *s)
{
	/* if the current character is NULL just return*/
	if (*s == '\0')
	{
		return;
	}

	/* otherwise print the next characters in the string */
	else
	{
		print_rev_rec(s + 1);
	}

	/* print the current character */
	_putchar(*s);
}
