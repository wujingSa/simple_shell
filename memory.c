#include "main.h"

/**
 * _memcpy - Copies data from a source pointer to a destination pointer.
 * @newptr: Destination pointer to copy data to.
 * @ptr: Source pointer to copy data from.
 * @size: Number of bytes to copy from source to destination.
 * Return: No return value.
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - Adjusts the size of a memory block.
 * @ptr: Pointer to the previously allocated memory block.
 * @old_size: Size, in bytes, of the current allocated space for ptr.
 * @new_size: New size, in bytes, for the resized memory block.
 * Return: Pointer to the adjusted memory block.
 * If new_size equals old_size, returns ptr without changes.
 * If malloc fails to allocate memory for the resized block, returns NULL.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - Resizes a dynamically allocated mem block for a double ptr.
 * @ptr: Pointer to the memory block previously allocated.
 * @old_size: Size, in bytes, of the currently allocated space for ptr.
 * @new_size: New size, in bytes, for the resized memory block.
 * Return: Pointer to the resized memory block.
 * If new_size equals old_size, returns ptr without changes.
 * If malloc fails to allocate memory for the resized block, returns NULL.
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
