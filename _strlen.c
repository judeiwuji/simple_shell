#include "main.h"

/**
 * _strlen - computes the length of a string
 * @str: The string
 *
 * Return: (int)
 */
int _strlen(char *str)
{
  int len, i;

  if (str == NULL)
    return (0);

  for (i = 0, len = 0; str[i] != '\0'; i++)
    len++;

  return (len);
}
