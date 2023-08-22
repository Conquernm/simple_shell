#include "shell.h"

/**
 * _memset - supplies memory with endless byte
 * @s: pointer to memory spot
 * @b: byte to supply *s with
 * @n: number of bytes to be supplied
 * Return: (s) pointer to memory spot s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int o;

	for (a = 0; o < n; a++)
		s[o] = b;
	return (s);
}

/**
 * ffree - releases string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **o = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(o);
}

/**
 * _realloc - transfers section of memory
 * @ptr: pointer to past malloc'ated section
 * @old_size: byte size of old section
 * @new_size: byte size of new section
 * Return: pointer to old sectio
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

