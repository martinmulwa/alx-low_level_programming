#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - prints it's own opcodes
 * @argc: number of commandline arguments
 * @argv: array containing all commandline arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int num_bytes, i;
	char *byte_str;

	/* check usage */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	byte_str = (char *)main;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02hhx", byte_str[i]);

		if (i < num_bytes - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
