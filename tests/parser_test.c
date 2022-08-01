#include "../shell.h"

int main(int argc, char **argv)
{
  char str[] = "ls";
  char *token;

  int size = get_parsed_size(str, ' ');
  printf("%d\n", size);
}
