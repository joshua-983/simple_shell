#include "shell.h"

/**
 * get_environ - return the environment
 * @info: Structure argument
 *
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)/*check if environ is not available*/
	{
		info->environ = list_to_strings(info->env);/*convert linked list to info->env*/
		info->env_changed = 0;
	}

	return (info->environ); /*return array environment*/
}

/**
 * _unsetenv - an environment variable
 * @info: Structure argument
 *        constant function prototype.
 *  Return: 1 on delete, or 0
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t cdf = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), cdf);
			cdf = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		cdf++;
	}
	return (info->env_changed);
}

/**
 * _setenv - set environ var
 *
 * @info: Structure argument
 *
 * @var: string variable
 * @value: enviornment value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
