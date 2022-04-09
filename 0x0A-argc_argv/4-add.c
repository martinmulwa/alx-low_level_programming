#include <stdio.h>
#include <stdlib.h>

int is_valid_int(char *str);

/**
 * main - adds positive numbers
 * @argc: number of commandline arguments
 * @argv: list of commandline arguments
 *
 * Description:
 * - If no number is passed to the program, print 0, followed by a new line
 * - If one of the number contains symbols that are not digits, print Error,
 * followed by a new line, and return 1
 *
 * Return: 0 if successful. 1 if error
 */
int main(int argc, char **argv)
{
	int i;
	unsigned int total = 0;

	/* check correct usage */
	if (argc <= 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_valid_int(argv[i]))
		{
			printf("Error\n");
			return (1);
		}

		total += atoi(argv[i]);
	}

	printf("%u\n", total);

	return (1);
}

/**
 * is_valid_int - checks if a given string is a valid integer
 * @str: string to be checked
 *
 * Return: 1 if the given string is a valid integer. 0 otherwise.
 */
int is_valid_int(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
