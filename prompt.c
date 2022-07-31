#include "shell.h"

/**
 * prompt - Prompts for input
 * @str: The pointer to store user input
 * @mode: The mode of the shell
 *
 * Return: void
 */
void prompt(char **str, int *mode)
{
	size_t len = 0;

	if (!isatty(fileno(stdin)))
		*mode = 0;

	write(1, "($) ", 4);
	getline(str, &len, stdin);
}
