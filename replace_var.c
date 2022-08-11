#include "shell.h"

/**
 * replace_var - Replaces the variables in the string
 * @s: The string
 * @svar: The shell variables
 *
 * Return: char *
 */
char *replace_var(char *s, shell_var_t *svar)
{
	char *str = NULL, *key, *var, c;
	int i, j, m, len, len2;

	if (s == NULL)
		return (NULL);
	str = _realloc(str, 0, 2);
	for (i = 0, j = 0; s[i] != '\0'; i++)
	{
		c = s[i + 1];
		if (s[i] == '$' && (c != ' ' && c != '\0'))
		{
			key = NULL;
			key = _realloc(key, 0, 2);
			m = 0;
			i++;
			while (s[i] != ' ' && s[i] != '\0')
			{
				key[m++] = s[i++];
				key[m] = '\0';
				key = _realloc(key, _strlen(key), _strlen(key) + 1);
			}
			var = getVar(key, svar);
			if (var != NULL)
			{
				len = _strlen(str);
				len2 = _strlen(var);
				str = _realloc(str, len, len + len2 + 1);
				str = _strcat(str, var, 0);
				str = _strcat(str, " ", 0);
				j = _strlen(str) - 1;
				free(var);
			}
			continue;
		}
		str[j++] = s[i];
		str[j] = '\0';
		str = _realloc(str, _strlen(str), _strlen(str) + 2);
	}
	return (str);
}

/**
 * getVar - Gets the variable using the key
 * @key: the key to be used to get the value
 * @svar: shell variables
 * Return: char*
 */
char *getVar(char *key, shell_var_t *svar)
{
	char *var = NULL;

	if (_strcmp(key, "?") == 0)
		var = _itoa(svar->code);
	else if (_strcmp(key, "#") == 0)
		var = _itoa(svar->argc);
	else if (_strcmp(key, "$") == 0)
		var = _itoa((int)svar->pid);
	else
		var = _getenv(key);
	return (var);
}
