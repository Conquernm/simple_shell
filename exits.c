#include "shell.h"

/**
 **_strncpy - it copies a string
 *@dest: destination string to be copied to
 *@src: source string
 *@n: amount of chars to be copied
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int b, k;
	char *s = dest;

	b = 0;
	while (src[b] != '\0' && b < n - 1)
	{
		dest[b] = src[b];
		b++;
	}
	if (b < n)
	{
		k = b;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_strncat - the concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int b, k;
	char *s = dest;

	b = 0;
	k = 0;
	while (dest[b] != '\0')
		n++;
	while (src[k] != '\0' && k  < n)
	{
		dest[b] = src[k];
		b++;
		k++;
	}
	if (k < n)
		dest[b] = '\0';
	return (s);
}

/**
 **_strchr - it  locates a char in a string
 *@s: string to be parsed
 *@c: char to look for
 *Return: (s) a pointer to the memory area s
 *
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
