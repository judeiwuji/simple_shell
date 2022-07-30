/**
 * _strcat - concatenates two strings.
 * @src: The first part o the string
 * @dest: The second part of the string
 * @start: Where to start appending from src
 *
 * Return: dest pointer
 */
char *_strcat(char *dest, const char *const src, int start)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	j = start;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
