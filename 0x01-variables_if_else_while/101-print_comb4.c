#include <stdio.h>

/**
 * main - Prints all possible different combinations of 3-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int j;
	int k;

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			for (k = j + 1; k < 10; k++)
			{
				putchar('0' + i);
				putchar('0' + j);
				putchar('0' + k);

				if (i < 7)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}

	}

	putchar('\n');

	return (0);
}
