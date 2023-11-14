#include "shell.h"

char *handle_path(const char *cmd)
{
    int i;
    struct stat statbuf;
    char *tmp, **path;
    char fullpath[BUFSIZ];

    tmp = getenv("PATH");
    path = tokenizer(tmp, ":");
    if (path == NULL)
        return (NULL);
    for (i = 0; path[i]; i++)
    {
        strcpy(fullpath, path[i]);
        strcat(fullpath, "/");
        strcat(fullpath, cmd);
        if (stat(fullpath, &statbuf) == 0)
        {
            free_tokens(path);
            return (strdup(fullpath));
        }
        fullpath[0] = '\0';
    }
    free_tokens(path);
    return (NULL);
}

CMD_Status validate(char **cmd)
{
    struct stat statbuf;
    char *new_path, *ptr = *cmd;

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == '/')
            return (CMD_SLASH);
    }

    if (stat(*cmd, &statbuf) == -1)
    {
        new_path = handle_path(*cmd);
        if (new_path == NULL)
            return (CMD_NEXIST);
        free(*cmd);
        *cmd = new_path;
    }
    return (CMD_EXIST);
}