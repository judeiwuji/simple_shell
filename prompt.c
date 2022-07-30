#include "shell.h"

/**
 * prompt - Prompts for input
 * @str: The pointer to store user input
 *
 * Return: void
 */
void prompt(char **str)
{
	size_t len = 0;

	write(1, "($) ", 4);
	getline(str, &len, stdin);
}
