#include "shell.h"

void free_tokens(char **arr)
{
    int i = 0;

    //if (arr == NULL)
    //    return;
    for (; arr[i]; i++)
        free(arr[i]);
    free(arr);
}