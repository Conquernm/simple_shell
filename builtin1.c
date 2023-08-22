#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info: Structure containing potential arguments
 *  Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: the parameter struct
 * @str: string alias
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *q, c;
	int ret;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	c = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: the parameter struct
 * @str: string alias
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: alias node
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *c = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (c = node->str; c <= q; c++)
		_putchar(*c);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics alias builtin
 * @info: Structure containing potential arguments
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int b = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (b = 1; info->argv[b]; b++)
	{
		q = _strchr(info->argv[b], '=');
		if (q)
			set_alias(info, info->argv[b]);
		else
			print_alias(node_starts_with(info->alias, info->argv[b], '='));
	}

	return (0);
}
