#include "shell.h"

/**
 * main - A simple shell program
 * @argc: The total arguments
 * @argv: List of arguments passed to main
 * @env: List of key value environment variables
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
  char **args;
  char *str;

  while (1)
  {
    str = NULL;
    prompt(&str);
    args = parser(_trim(str), " ");
    if (args != NULL && args[0] != NULL)
      execCmd(args[0], args, env);
  }
  return (0);
}
