#include "3-calc.h"

/**
 * main - performs simple integer operations
 * @argc: number of commandline arguments
 * @argv: array containing all commandline arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int (*f)(int, int);
	char *op;
	int num1, num2;

	/* check usage */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	f = get_op_func(op);

	if (f == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	/* check for 0 division */
	if ((op[0] == '/' || op[0] == '%') && op[1] == '\0' && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", f(num1, num2));

	return (0);
}
