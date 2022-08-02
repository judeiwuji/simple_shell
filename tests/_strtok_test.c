#include "../shell.h"

int main(int argc, char **argv)
{
  char str[] = "ls -l /tmp | echo";
  char *token;

  token = _strtok(str, '|');
  while (token != NULL)
  {
    printf("%s\n", token);
    token = _strtok(NULL, '|');
  }
}
