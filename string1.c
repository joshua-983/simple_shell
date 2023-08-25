#include "shell.h"

/**
 * _strcpy - make copy of string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int acb = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[acb])
	{
		dest[acb] = src[acb];
		acb++;
	}
	dest[acb] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int usd = 0;

	if (!str)
		return;
	while (str[usd] != '\0')
	{
		_putchar(str[usd]);
		usd++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The char to print
 *
 * Return: On success 1 or 0 fail
 */
int _putchar(char c)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}

