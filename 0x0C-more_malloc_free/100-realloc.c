#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: the size, in bytes, of the allocated space for ptr
 * @new_size: the new size, in bytes of the new memory block
 *
 * - The contents will be copied to the newly allocated space,
 * in the range from the start of ptr up to the
 * minimum of the old and new sizes
 * - If new_size > old_size, the “added” memory should not be initialized
 * - If new_size == old_size do not do anything and return ptr
 * - If ptr is NULL, then the call is equivalent to malloc(new_size),
 * for all values of old_size and new_size
 * - If new_size is equal to zero, and ptr is not NULL,
 then the call is equivalent to free(ptr)
 *
 * Return: pointer to the newly allocated memory if successful. Otherwise NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned char *mem;
	unsigned char *ptr_cpy = ptr;
	unsigned int lim = (old_size < new_size) ? old_size : new_size;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* If new_size == old_size do not do anything and return ptr */
	if (new_size == old_size)
		return (ptr);

	/* allocate new space */
	mem = malloc(new_size);
	if (mem == NULL)
		return (NULL);

	/* copy all the contents from ptr to the new memory */
	for (i = 0; i < lim; i++)
		mem[i] = ptr_cpy[i];

	/* free the previous memory */
	if (ptr != NULL)
		free(ptr);

	return (mem);
}
