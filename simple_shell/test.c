#include "shell.h"

void print(const char **av)
{
    for (int i = 0; av[i]; i++)
        printf("av[%d] = %s\n", i, av[i]);
    free_tokens((char **)av);
}