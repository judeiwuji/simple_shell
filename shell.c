#include "main.h"

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
  char *cmd;
  char **args;
  char str[] = "ls -l | cp";
  int i = 0;

  args = parser(str, "|");
  if (args != NULL)
  {
    while (args[i] != NULL)
      printf("%s\n", args[i++]);
  }
  return (0);
}
