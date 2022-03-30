#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line, recursively
 * @s: the string to be printed
 */
void _puts_recursion(char *s)
{
	/* print new line at the end of the string */
	if ((*s) == '\0')
	{
		_putchar('\n');
	}
	else
	{
		/* print the current character */
		_putchar(*s);

		/* print the next characters */
		_puts_recursion(s + 1);
	}
}
