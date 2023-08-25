#include "shell.h"

/**
 * clear_info _ info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int instructions = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
	for (instructions = 0; info->argv && info->argv[instructions]; instructions++)
			;
		info->argc = instructions;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info structure
 * @info: struct argument
 * @all: freeing all fields
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
	if (!info->cmd_buf)/*check if cmd_buf is unavilable*/
	free(info->arg);/*free memory*/
	if (info->env)
	free_list(&(info->env));
	if (info->history)
	free_list(&(info->history));
	if (info->alias)
	free_list(&(info->alias));
	ffree(info->environ);
	info->environ = NULL;
	bfree((void **)info->cmd_buf);
	if (info->readfd > 2)
	close(info->readfd);/*close the file descriptor*/
	_putchar(BUF_FLUSH);/*flush the output buffer*/
	}
}

