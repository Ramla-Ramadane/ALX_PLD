#include "shell.h"

int main(int ac, char **av)
{
    char *line = NULL, *prompt = "hard_shell~$";
    char **tokens;
    size_t size = 0;
    int mode = isatty(STDIN_FILENO);
    FILE *fp;

    if (ac != 1)
    {
        fp = fopen(av[1], "r");
        if (fp == NULL)
            printf("Couldn't read from file...\n");    
    }
    else
        fp = stdin;
    while (true) {
        if (mode == 1 && fp == stdin)
            fprintf(stdout, "%s ", prompt);
        if (getline(&line, &size, fp) == -1) {
            if (mode == 1)
                putchar('\n');
            break;
        }
        tokens = tokenizer(line, "\n \t");
        if (tokens == NULL)
            continue;
        //print((const char **) tokens);
        switch(validate(&tokens[0]))
        {
            case (CMD_EXIST):
                execute(tokens);
                break;
            case (CMD_NEXIST):
                printf("Command not found...\n");
                break;
            case (CMD_SLASH):
                printf("There is a slash...\n");
                break;
        }
        free_tokens(tokens);
    }
    if (fp != stdin)
        fclose(fp);
    free(line);
}