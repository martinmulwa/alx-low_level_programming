#include "main.h"
#include <stdlib.h>

void *_memset(void *arr, unsigned int n);

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of each element
 *
 * The memory is set to zero
 *
 * Return: a pointer to the allocated memory
 * If nmemb or size is 0, then _calloc returns NULL
 * if malloc fails, then _calloc returns NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);

	/* set memory to 0 */
	_memset(mem, nmemb * size);

	return (mem);
}

/**
* _memset - fills memory with a constant byte 0
* @arr: memory area to fill in
* @n: number of bytes to write
*
* Return: a pointer to the memory area s
*/
void *_memset(void *arr, unsigned int n)
{
	unsigned char *new_arr = arr;

	while (n > 0)
	{
		*new_arr = 0;
		new_arr++;
		n--;
	}

	return (arr);
}
