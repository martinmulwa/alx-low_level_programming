#include <stdio.h>

/**
 * main - Print the alphabet in lowercase, in reverse
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 97 + 25; i >= 97; i--)
		putchar(i);

	putchar('\n');

	return (0);
}
