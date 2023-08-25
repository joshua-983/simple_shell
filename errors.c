#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: 0.
 */
void _eputs(char *str)
{
	int john = 0;

	if (!str)
		return;
	while (str[john] != '\0')
	{
		_eputchar(str[john]);
		john++;
	}
}

/**
 * _eputchar - character that write to str
 * @c: The character to print
 *
 * Return: 1 or -1
 */
int _eputchar(char c)
{
	static int as;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || as >= WRITE_BUF_SIZE)
	{
		write(2, buf, as);
		as = 0;
	}
	if (c != BUF_FLUSH)
		buf[as++] = c;
	return (1);
}

/**
 * _putfd - write the char. to fd
 * @c: The character to print
 * @fd: file descriptor
 *
 * Return: 1 or -1.
 */

int _putfd(char c, int fd)
{
	static int abc;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || abc >= WRITE_BUF_SIZE)
	{
		write(fd, buf, abc);
		abc = 0;
	}
	if (c != BUF_FLUSH)
		buf[abc++] = c;
	return (1);
}

/**
 * _putsfd - an input string to print
 * @str: the string to be printed
 * @fd: file descriptor.
 *
 * Return: the number of charaters
 */
int _putsfd(char *str, int fd)
{
	int ak = 0;

	if (!str)
		return (0);
	while (*str)
	{
		ak += _putfd(*str++, fd);
	}
	return (ak);
}
