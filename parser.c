#include "main.h"

/**
 * parser - Parses the input and seperate it into
 * command and args
 * @cmd: The command in the input
 * @args: The arguments for this command
 *
 * Return: 0 on success, 1 otherwise
 */
int parser(char *str, char *cmd, char **args)
{
  char *token;
  if (str == NULL)
    return (1);

  args = malloc(sizeof(char *));
  if (args == NULL)
    return (1);

  token = strtok(str, " ");
  cmd = token;
  while (token != NULL)
  {
    }
}
