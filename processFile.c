#include "shell.h"

/**
 * processFile - Reads a file with commands
 * @str: The buffer to store the read string
 * @filename: The file to be read
 *
 * Return: 1 on success, 0 otherwise
 */
int processFile(char *filename, char **str)
{
  char buf[1024];
  static char **data;
  static int fd = 0;
  int status;

  if (fd == 0)
  {
    data = NULL;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
      return (0);
  }
  if (data == NULL)
  {
    status = read(fd, buf, 1024);
    if (status >= 0)
      data = parser(buf, "\n");
  }

  if (data != NULL)
  {
    *str = *(data++);
    if (*data != NULL)
      return (1);
  }
  return (0);
}
