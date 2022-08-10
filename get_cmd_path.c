#include "shell.h"

/**
 * getCmdPath - Search for a given command in the PATH
 * @cmd: The command to be searched
 *
 * Return: path, otherwise NULL
 */
char *getCmdPath(char *cmd)
{
	struct stat st;
	char *path, *token, *cmdPath = NULL;
	int size;

	if (_strlen(cmd) == 0)
		return (NULL);
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	token = _tokenize(path, ":");
	while (token != NULL)
	{
		size = _strlen(token) + _strlen(cmd);
		cmdPath = malloc(sizeof(char) * size + 2);
		if (cmdPath == NULL)
			return (NULL);
		cmdPath[0] = '\0';
		_strcat(cmdPath, token, 0);
		_strcat(cmdPath, "/", 0);
		_strcat(cmdPath, cmd, 0);
		free(token);
		if (stat(cmdPath, &st) == 0)
		{
			free(path);
			return (cmdPath);
		}
		free(cmdPath);
		token = _tokenize(NULL, ":");
	}
	free(path);
	return (cmd);
}
