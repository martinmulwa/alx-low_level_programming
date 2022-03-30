#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse, recursively
 * @s: string to print
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;

	/* print the previous characters */
	_print_rev_recursion(s + 1);

	/* print the current character */
	_putchar(*s);
}
