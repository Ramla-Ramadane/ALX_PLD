#include "shell.h"

int main(int ac, char **av)
{
    char *line = NULL, *prompt = "hard_shell~$";
    char **tokens;
    size_t size = 0;
    int mode = isatty(STDIN_FILENO);

    while (true) {
        if (mode == 1)
            fprintf(stdout, "%s ", prompt);
        if (getline(&line, &size, stdin) == -1) {
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
    free(line);
}