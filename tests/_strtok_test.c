#include "../shell.h"

int main(int argc, char **argv)
{
  char str[] = "ls && ls -l /tmp || echo && mkdir test && cd /tmp";
  char *token;

  token = _strtok(str, "||&&");
  while (token != NULL)
  {
    printf("%s\n", _trim(token));
    token = _strtok(NULL, "||&&");
  }
}

/** Compile */
/*
gcc ../_strtok.c ../_strlen.c ../_strcpy.c ../_strcmp.c ../_realloc.c _strtok_test.c ../trim.c ../_reverse_str.c -o test
*/
