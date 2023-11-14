#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>

//#define CMD_NEXIST   -1
//#define CMD_EXIST     0
typedef enum {
    CMD_EXIST, CMD_NEXIST, CMD_SLASH
} CMD_Status;

/* Test function */
void print(const char **av);

extern char **environ;
char **tokenizer(const char *str, const char *delim);
size_t words_count(const char *str, const char *delim);
void free_tokens(char **av);
CMD_Status validate(char **cmd);
void execute(char **cmd_args);
#endif  /* shell.h */