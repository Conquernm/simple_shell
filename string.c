#include "shell.h"

/**
 * _strlen - replaces length of a string
 * @s: string of which length to check
 *
 * Return: decimal length of string
 */
int _strlen(char *s)
{
int a = 0;

if (!s)
return (0);

while (*s++)
a++;
return (a);
}

/**
 * _strcmp - run lexicogarphic similarity of two strings
 * @s1: first string
 * @s2: second string
 * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - tests whether needle begins with haystack
 * @haystack: string to check
 * @needle: substring to locate
 * Return: the mark of next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - joins two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
