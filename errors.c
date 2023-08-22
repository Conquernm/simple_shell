#include "shell.h"

/**
 * _eputs - it prints an input string
 * @str: the string to be printed
 * Return: nothing
 */
void _eputs(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_eputchar(str[b]);
		b++;
	}
}

/**
 * _eputchar -it  writes the char c to stder
 * @c:  char to print
 *
 *
 * Return: 1 on success and -1 on error
 */
int _eputchar(char c)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}

/**
 * _putfd - it  writes the character c to given fd
 * @c: char to print
 * @fd: fd to write to
 * Return: 1 on success and -1 on error.
 */
int _putfd(char c, int fd)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(fd, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}

/**
 * _putsfd - it prints an input string
 * @str: str to be printed
 * @fd: fd to write on
 * Return:  number of chars put
 */
int _putsfd(char *str, int fd)
{
	int b = 0;

	if (!str)
		return (0);
	while (*str)
	{
		b += _putfd(*str++, fd);
	}
	return (b);
}
