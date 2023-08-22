#include "shell.h"

/**
 * _erratoi - it converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers, converted number otherwise and -1 on error
 */
int _erratoi(char *s)
{
	int b = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (b = 0;  s[b] != '\0'; b++)
	{
		if (s[b] >= '0' && s[b] <= '9')
		{
			result *= 10;
			result += (s[b] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: parameter & return info struct
 * @estr: the string containing specified error type
 * Return: 0 if no numbers, converted number otherwise and -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - func prints a decimal (integer)
 * @input: input
 * @fd: fd to write to
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int b, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (b = 1000000000; b > 1; b /= 10)
	{
		if (_abs_ / b)
		{
			__putchar('0' + current / b);
			count++;
		}
		current %= b;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter func, a clone
 * @num: number
 * @base: base
 * @flags: the argument flags
 * Return: the string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - the func replaces first instance of '#' with '\0'
 * @buf: the address of the string to modify
 * Return: 0;
 */
void remove_comments(char *buf)
{
	int b;

	for (b = 0; buf[b] != '\0'; b++)
		if (buf[b] == '#' && (!b || buf[b - 1] == ' '))
		{
			buf[b] = '\0';
			break;
		}
}
