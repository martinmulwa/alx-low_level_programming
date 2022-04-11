#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees dogs
 * @d: dog_t to be freed
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	/* free name field */
	if (d->name != NULL)
		free(d->name);

	/* free owner field */
	if (d->owner != NULL)
		free(d->owner);

	/* free dog */
	free(d);
}
