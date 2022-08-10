#include "shell.h"

/**
 * execCmd - Executes a given command
 * @sh: The name used to start the shell
 * @cmd: The command to be executed. This should be the
 * full path to this command
 * @args: List of arguments for this cmd, the first
 * item in this list must be the command to be executed
 *
 * Return: 0 on success, 1 otherwise
 */
int execCmd(char *sh, char *cmd, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror(sh);
		return (1);
	}

	if (pid == 0)
	{
		if ((execve(cmd, args, environ)) == -1)
		{
			perror(sh);
			exit(1);
		}
		exit(0);
	}
	else
	{
		waitpid(-1, &status, 0);
		return (WEXITSTATUS(status));
	}
}
