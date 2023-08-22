#include "shell.h"

/**
 * input_buf - it buffers chained commands
 * @info: the parameter struct
 * @buf: the address of buffer
 * @len: the address of len variables
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t k = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		k = getline(buf, &len_p, stdin);
#else
		k = _getline(info, buf, &len_p);
#endif
		if (k > 0)
		{
			if ((*buf)[k - 1] == '\n')
			{
				(*buf)[k - 1] = '\0'; /* remove trailing newline */
				k--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = k;
				info->cmd_buf = buf;
			}
		}
	}
	return (k);
}

/**
 * get_input - it gets a line minus the newline
 * @info: the parameter struct
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t b, j, len;
	ssize_t k = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	k = input_buf(info, &buf, &len);
	if (k == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = b; /* init new iterator to current buf position */
		p = buf + b;

		check_chain(info, buf, &j, b, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		b = j + 1; /* increment past nulled ';'' */
		if (b >= len) /* reached end of buffer? */
		{
			b = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf;
	return (k);
}

/**
 * read_buf - it reads a buffer
 * @info: the parameter struct
 * @buf: the buffer
 * @i: the size
 *
 * Return: k
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t k = 0;

	if (*i)
		return (0);
	k = read(info->readfd, buf, READ_BUF_SIZE);
	if (k >= 0)
		*i = k;
	return (k);
}

/**
 * _getline - it gets the next line of input from STDIN
 * @info: the parameter struct
 * @ptr: the address of pointer to buffer, preallocated or NULL
 * @length: the size of preallocated ptr buffer if not NULL
 * Return: z
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t b, len;
	size_t l;
	ssize_t r = 0, z = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		z = *length;
	if (b == len)
		b = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + b, '\n');
	l = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, z, z ? z + l : l + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (z)
		_strncat(new_p, buf + b, l - b);
	else
		_strncpy(new_p, buf + b, l - b + 1);

	z += l - b;
	b = l;
	p = new_p;

	if (length)
		*length = z;
	*ptr = p;
	return (z);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num:  sig number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
