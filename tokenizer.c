#include "shell.h"

/**
 * strtow - break a string into words. Rerun delimiters are rejected
 * @str: input string
 * @d: delimeter string
<<<<<<< HEAD
 * Return: pointer to an array of strings, or NULL on failure
=======
 * Return: pointer to an array of strings, or NULL on failure
>>>>>>> ed45735467425ba799fc638f4b6d21a054ce2568
 */

char **strtow(char *str, char *d)
{
int a, g, b, f, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (a = 0; str[a] != '\0'; a++)
if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (a = 0, g = 0; g < numwords; g++)
{
while (is_delim(str[a], d))
a++;
b = 0;
while (!is_delim(str[a + b], d) && str[a + b])
b++;
s[g] = malloc((b + 1) * sizeof(char));
if (!s[g])
{
for (b = 0; b < g; b++)
free(s[b]);
free(s);
return (NULL);
}
for (f = 0; f < b; f++)
s[g][f] = str[a++];
s[g][f] = 0;
}
s[g] = NULL;
return (s);
}

/**
 * strtow2 - breaks a string into words
 * @str: input string
 * @d: delimeter
 * Return: pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
int a, g, b, f, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (a = 0; str[a] != '\0'; a++)
<<<<<<< HEAD
if ((str[a] != d && str[a + 1] == d) ||
				    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
=======
if ((str[a] != d && str[a + 1 == d]) ||(str[a] != d && !str[a + 1]) || str[a + 1] == d)
>>>>>>> ed45735467425ba799fc638f4b6d21a054ce2568
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (a = 0, g = 0; g < numwords; g++)
{
while (str[a] == d && str[a] != d)
a++;
b = 0;
<<<<<<< HEAD
while (str[a + b] != d && str[a + b && str[a + b] != d])
b++;
s[g] = malloc((b + 1) * sizeof(char));
if (!s[g])
{
for (b = 0; b < g; b++)
free(s[b]);
free(s);
return (NULL);
}
for (f = 0; f < b; f++)
s[g][f] = str[a++];
s[g][f] = 0;
}
s[g] = NULL;
return (s);
=======
		while (str[a + b] != d && str[a + b] && str[a + b] != d)
			b++;
		s[g] = malloc((b + 1) * sizeof(char));
		if (!s[g])
		{
			for (b = 0; b < g; b++)
				free(s[b]);
			free(s);
			return (NULL);
		}
		for (f = 0; f < b; f++)
			s[g][f] = str[a++];
		s[g][f] = 0;
	}
	s[g] = NULL;
	return (s);
>>>>>>> ed45735467425ba799fc638f4b6d21a054ce2568
}

