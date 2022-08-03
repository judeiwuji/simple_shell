#include "shell.h"

/**
 * main - A simple shell program
 * @argc: The total arguments
 * @argv: List of arguments passed to main
 *
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *str;
	int mode = 1;
	int exitCode = 0;
	int argCount = 0;
	pid_t pid __attribute__((unused));

	pid = getpid();
	while (mode)
	{
		str = NULL;
		prompt(&str, &mode);

		str = removeComment(str);
		if (processLogical(argv[0], str, &exitCode, &argCount) == 1)
			continue;
		else if (processCmdSp(argv[0], str, &exitCode, &argCount) == 1)
			continue;
		else
			exitCode = processcmd(argv[0], str, &argCount);
		free(str);
	}
	return (0);
}
