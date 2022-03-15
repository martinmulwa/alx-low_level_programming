#include "main.h"

/**
 * main - prints _putchar, followed by a new lin
 *
 * Return: Always 0.
 */
int main(void)
{
	char msg[] = "_putchar";
	int n = sizeof(msg) / sizeof(char);
	int i;

	for (i = 0; i < n; i++)
		_putchar(msg[i]);

	_putchar('\n');

	return (0);
}
