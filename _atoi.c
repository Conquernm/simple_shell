#include "shell.h"

/**
 * interactive - it returns true if shell is interactive mode
 * @info: the struct address
 * Return: 1 if interactive mode, 0 if not
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: charecter to check
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - it checks for alphabetic character
 * @c: character to input
 * Return: 1 if c is alphabetic, 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - it converts a string to an integer
 * @s: string to be converted
 * Return: 0 if no numbers in string, converted number if there is
 */

int _atoi(char *s)
{
	int b, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (b = 0; s[b] != '\0' && flag != 2; b++)
	{
		if (s[b] == '-')
			sign *= -1;

		if (s[b] <= '9' && s[b] >= '0')
		{
			flag = 1;
			result *= 10;
			result += (s[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
