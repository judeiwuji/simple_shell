#include "../shell.h"

int main(int argc, char **argv)
{
  char str[] = "ls && ls -l /tmp || echo && mkdir test && cd /tmp";
  char str2[] = "ls";
  char *token;

  token = _tokenize(str2, " ");
  while (token != NULL)
  {
    printf("[%s]\n", token);
    token = _tokenize(NULL, " ");
  }
}

/** Compile */
/*
 gcc ../_tokenize.c ../_strlen.c ../_strcpy.c ../_strcmp.c ../_realloc.c _strtok_test.c ../trim.c ../_reverse_str.c -o test
*/
