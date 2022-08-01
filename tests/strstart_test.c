#include "../shell.h"

int main(int argc, char **argv)
{
  char *t1 = "Johnson";
  char *t2 = "John";

  printf("%s - %s [%d]\n", t1, t2, _strstart(t1, t2));
  printf("%s - %s [%d]\n", t2, t1, _strstart(t2, t1));

  t1 = "tests";
  t2 = "ts";
  printf("%s - %s [%d]\n", t1, t2, _strstart(t1, t2));
  printf("%s - %s [%d]\n", t2, t1, _strstart(t2, t1));
}
