#include "shell.h"

/**
 * _strcpy -  copies a string.
 * @src: the string to be copied from
 * @dest: the string to be copied to
 *
 * Return: A pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
