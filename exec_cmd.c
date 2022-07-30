#include "shell.h"

/**
 * execCmd - Executes a given command
 * @cmd: The command to be executed. This should be the
 * full path to this command
 * @args: List of arguments for this cmd, the first
 * item in this list must be the command to be executed
 * @env: The environment to be used to exec this cmd
 *
 * Return: 0 on success, 1 otherwise
 */
int execCmd(char *cmd, char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("sh");
		return (1);
	}

	if (pid == 0)
	{
		if ((execve(cmd, args, env)) == -1)
			perror("sh");
		exit(0);
	}
	else
	{
		wait(&status);
		return (0);
	}
}
