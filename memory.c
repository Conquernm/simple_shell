#include "shell.h"

/**
 * bfree - releases index & invalidates address
 * @ptr: the mark of the index to release
 * Return: 1 if released, or else 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
