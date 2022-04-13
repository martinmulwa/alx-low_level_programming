#include "3-calc.h"

/**
 * get_op_func - selects the correct function using a given string
 * @s: operator passed as argument to the program
 *
 * Return: a pointer to the function that corresponds to s. Otherwise NULL
 */
int (*get_op_func(char *s))(int a, int b)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	int i;
	i = 0;

	while (i < 6)
	{
		if (ops[i].op != NULL && s[0] == ops[i].op[0] && s[1] == '\0')
			return (ops[i].f);

		i++;
	}

	return (NULL);
}
