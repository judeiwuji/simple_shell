#include "main.h"

/**
 * getCmdPath - Search for a given command in the PATH
 * @cmd: The command to be searched
 *
 * Return: path, otherwise NULL
 */
char *getCmdPath(char *cmd)
{
	struct stat st;
	char *path = getenv("PATH");
	char *token;
	char *cmdPath = NULL;
	int size;

	if (_strlen(cmd) == 0)
		return (NULL);
	if (_strlen(cmd) > 2)
	{
		if (cmd[0] == '.' && cmd[1] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (cmd);
			else
				return (NULL);
		}
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		size = _strlen(token) + _strlen(cmd);
		cmdPath = malloc(sizeof(char) * size + 2);
		cmdPath[0] = '\0';
		_strcat(cmdPath, token, 0);
		_strcat(cmdPath, "/", 0);
		_strcat(cmdPath, cmd, 0);
		if (stat(cmdPath, &st) == 0)
			return (cmdPath);

		token = strtok(NULL, ":");
	}
	free(cmdPath);
	return (NULL);
}