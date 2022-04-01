#include <stdio.h>
#include <stdlib.h>

int is_valid_int(char *s);

/**
 * main - prints the minimum number of coins
 * to make change for an amount of money
 * @argc: number of commandline arguments
 * @argv: list of commandline arguments
 *
 * Description:
 * - if the number of arguments passed to your program is not exactly 1,
 * print Error, followed by a new line, and return 1
 * - If the number passed as the argument is negative, print 0,
 * followed by a new line
 *
 * Return: 0 if successful. 1 if error
 */
int main(int argc, char **argv)
{
	int i;
	int cents;
	int new_coins;
	int coins = 0;
	int coin_values[] = {25, 10, 5, 2, 1};

	/* check for correct usage */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	/* check if the argument is a valid integer */
	if (!is_valid_int(argv[1]))
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	/* check if the number of cents is -ve */
	if (cents < 0)
	{
		printf("%d\n", 0);
		return (0);
	}

	for (i = 0; i < 5; i++)
	{
		new_coins = cents / coin_values[i];
		coins += new_coins;

		cents -= (new_coins * coin_values[i]);
	}

	printf("%d\n", coins);

	return (0);
}

/**
 * is_valid_int - checks if a string is a valid integer
 * @s: string
 *
 * Return: 1 is s is a valid integer. 0 otherwise
 */
int is_valid_int(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);

		s++;
	}

	return (1);
}
