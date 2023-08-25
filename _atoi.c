#include "shell.h"

/**
 * interactive - returns  code to be true if shell is in interactive mode
 * @info: the structure address
 *
 * Return: 1, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if the , 0 if false
 */

int is_delim(char c, char *delim)

{
	int qw; /*counter variable for iterating the delimiter string*/

	for (qw = 0; delim[qw]; qw++)/*loop through the string until null terminator*/
	{
	if (c == delim[qw])/*check if the current char. to matches checked*/
	return (1); /*return 1 if match is found*/
	}
	return (0); /*return 0 if char. is not found in the delimiter*/
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to be checked
 * Return: 1 if c is alphabetic character, 0 vise versa
 */

int _isalpha(int c)

{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	return (1);/*if character is alphabetic*/
	else
	return (0);/*if character is lowercase*/
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)

{
	int ab, sign = 1, flag = 0, output;

	unsigned int result = 0;

	for (ab = 0; s[ab] != '\0' && flag != 2; ab++)
	{
	if (s[ab] == '-')
	sign *= -1;

	if (s[ab] >= '0' && s[ab] <= '9')
	{
	flag = 1;/*indicate that the digit are being processed*/
	result *= 10;/*multiply by ten to shift digit to left*/
	result += (s[ab] - '0');
	}
	else if (flag == 1)
	flag = 2;/*digit process is complete*/
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);/*Return the converted integer value*/
}
