#include "shell.h"

/**
 * __exit - Terminates the program
 * @args: The enviroment list
 *
 * Return: 1 on failure
 */
int __exit(char **args)
{
  if (args != NULL && args[1] != NULL)
    exit(_atoi(args[1]));
  exit(0);
  return (1);
}
