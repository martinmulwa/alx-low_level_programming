#include <stdio.h>
#include <stdlib.h>

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
	int cents, new_coins, i;
	int values[] = {25, 10, 5, 2, 1};
	int coins = 0;

	/* check correct usage */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/* find minimum number of coins */
	while (cents > 0)
	{
		for (i = 0; i < 5; i++)
		{
			if (cents >= values[i])
			{
				new_coins = cents / values[i];
				coins = coins + new_coins;
				cents = cents - (values[i] * new_coins);
			}

			if (cents == 0)
				break;
		}
	}

	printf("%d\n", coins);

	return (0);
}
