#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: minimum integer in array
 * @max: maximum integer in array
 *
 * The array created should contain all the values
 * from min (included) to max (included), ordered from min to max
 *
 * Return: pointer to the newly created array
 * If min > max, return NULL
 * If malloc fails, return NULL
 */
int *array_range(int min, int max)
{
	int len = (max - min) + 1;
	int i;
	int *arr;

	if (len < 0)
		return (NULL);

	arr = malloc(sizeof(int) * len);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		arr[i] = min + i;

	return (arr);
}
