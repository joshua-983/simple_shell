#include "shell.h"

/**
 * _memset - fills memory
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be used
 * Return: pointer memory of s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int cv;

	for (cv = 0; cv < n; cv++)
		s[cv] = b;
	return (s);
}

/**
 * ffree - frees string
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size 
 * @new_size: byte size of new block
 *
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);/*memory allocation*/
	if (!p)/*if allocation fails , return null*/
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

