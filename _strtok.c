#include "shell.h"

char *_strtok(char *str, char delim)
{
	static char *data;
	char *res = NULL;
	int i = 0, len;

	if (str != NULL)
		data = str;

	if (data == NULL)
		return (NULL);
	while (data[0] != '\0')
	{
		if (data[0] == delim)
		{
			++data;
			break;
		}
		len = _strlen(res);
		res = _realloc(res, len, len + 2);
		res[i++] = data[0];
		res[i] = '\0';
		++data;
	}
	return (res);
}
