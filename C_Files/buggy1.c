#include <stdio.h>

int main(void)
{
  string name = get_string("What's your name?\n");
  printf("Hello %s", name);
  return 0;
}