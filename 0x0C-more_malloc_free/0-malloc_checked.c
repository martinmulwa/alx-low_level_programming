#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: size of memory to allocate
 *
 * Return: pointer to the allocated memory
 * if malloc fails, the malloc_checked function should cause normal process
 * termination with a status value of 98
 */
void *malloc_checked(unsigned int b)
{
	void *mem = malloc(b);

	/* check if malloc fails */
	if (mem == NULL)
		exit(98);

	return mem;
}
