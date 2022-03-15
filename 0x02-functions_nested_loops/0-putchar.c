#include "main.h"

/**
 * main - prints _putchar, followed by a new lin
 *
 * Return: Always 0.
 */
int main(void)
{
	char msg[] = "_putchar";
	int i;

	for (i = 0; i < 8; i++)
		_putchar(msg[i]);

	_putchar('\n');

	return (0);
}
