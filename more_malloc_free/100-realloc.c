#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the previously allocated memory
 * @old_size: size in bytes of the old block
 * @new_size: size in bytes of the new block
 *
 * Return: pointer to the new block, ptr, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old_ptr;
	unsigned int i, min;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	old_ptr = ptr;
	min = (old_size < new_size) ? old_size : new_size;
	for (i = 0; i < min; i++)
		new_ptr[i] = old_ptr[i];
	free(ptr);
	return (new_ptr);
}
