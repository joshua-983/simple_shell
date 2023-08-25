#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination
 *@src: the string
 *@n: characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int ink, joyce;
	char *s = dest;

	ink = 0;
	while (src[ink] != '\0' && ink < n - 1)
	{
		dest[ink] = src[ink];
		ink++;
	}
	if (ink < n)
	{
		joyce = ink;
		while (joyce < n)
		{
			dest[joyce] = '\0';
			joyce++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: 1st string
 *@src: 2nd string
 *@n: the amount of memory
 *Return: the concatenation
 */
char *_strncat(char *dest, char *src, int n)
{
	int bad, good;
	char *s = dest;

	bad = 0;/*initialize bad counter for dest string*/
	good = 0;/*initialize good counter for src string*/
	while (dest[bad] != '\0')
		bad++;
	while (src[good] != '\0' && good < n)/*append the character from src to dest*/
	{
		dest[bad] = src[good];
		bad++;/*increment to next position*/
		good++;/*increment to next character*/
	}
	if (good < n)
		dest[bad] = '\0';
	return (s);/*concatenated string*/
}

/**
 **_strchr -string character
 *@s: parse string
 *@c: character
 *Return: pointer to memory
 */
char *_strchr(char *s, char c)
{
	do {/*loop to the end of the string*/
		if (*s == c) /*check if current char is = target c*/
			return (s); /*return current pointer*/
	} while (*s++ != '\0');
/*return NULL, IF c not found*/
	return (NULL);
}

