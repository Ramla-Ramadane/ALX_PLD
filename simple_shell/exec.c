#include "shell.h"

void execute(char **cmd_args)
{
    switch (fork())
    {
        case -1:
            printf("fork() fails\n");
            break;
        case 0:
            execve(cmd_args[0], cmd_args, environ);
            perror("shell");
            exit(1);
        default:
            wait(NULL);
    }
}