#include "../shell.h"

int main(int argc, char **argv)
{
  char str[] = "ls && ls -l /tmp || echo && mkdir test && cd /tmp";
  char *token;

  token = _tokenize(str, "||&&");
  while (token != NULL)
  {
    printf("%s\n", _trim(token));
    token = _tokenize(NULL, "||&&");
  }
}

/** Compile */
/*
gcc ../_strtok.c ../_strlen.c ../_strcpy.c ../_strcmp.c ../_realloc.c _strtok_test.c ../trim.c ../_reverse_str.c -o test
*/
