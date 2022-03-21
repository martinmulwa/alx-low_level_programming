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
	/* check if the next character is not NULL */
	if (*(s + 1))
		print_rev_rec(s + 1);

	/* if the next character is NULL then we are at the end of the string */
	_putchar(*s);
}
