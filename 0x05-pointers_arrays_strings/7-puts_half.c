#include "main.h"

int _strlen(char *s);

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: address of first character in the string
 *
 * Description:
 * The function should print the second half of the string
 * If the number of characters is odd,
 * the function should print the last n characters of the string
 * where n = (length_of_the_string - 1) / 2
 */
void puts_half(char *str)
{
	int i = 0;
	int length = _strlen(str);

	while (*str)
	{
		if (i > ((length - 1) / 2))
			_putchar(*str);

		str++;
		i++;
	}

	_putchar('\n');
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
