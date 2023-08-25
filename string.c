#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: lenght of string
 *
 * Return: integer
 */
int _strlen(char *s)
{
	int p = 0;

	if (!s)
		return (0);

	while (*s++)
		p++;
	return (p);
}

/**
 * _strcmp - comparison of two strangs.
 * @s1: 1st strang
 * @s2: 2nd strang
 *
 * Return: negative or positive
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - starts with haystack
 * @haystack: string to search
 * @needle: substring to find
 *
 * Return: next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: source buffer
 *
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

