#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase excep 'q' and 'e'
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 97; i < 97 + 26; i++)
	{
		if (i == 'e' || i == 'q')
			continue;
		else
			putchar(i);
	}

	putchar('\n');

	return (0);
}
