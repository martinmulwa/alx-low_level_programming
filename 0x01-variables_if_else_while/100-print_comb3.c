#include <stdio.h>

/**
 * main - Prints all possible combinations of 2-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			putchar('0' + i);
			putchar('0' + j);

			if (i < 8)
			{
				putchar(',');
				putchar(' ');
			}
		}

	}

	putchar('\n');

	return (0);
}
