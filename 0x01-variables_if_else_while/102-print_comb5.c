#include <stdio.h>

/**
 * main - Prints all possible combinations of two two-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int j;

	for (i = 0; i < 100; i++)
	{
		for (j = i + 1; j < 100; j++)
		{
			/* print the first number */
			putchar('0' + ((i / 10) % 10));
			putchar('0' + (i % 10));

			putchar(' ');

			/* print the second number */
			putchar('0' + ((j / 10) % 10));
			putchar('0' + (j % 10));

			if (i < 98)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
