#include "shell.h"
char **tokenizer(char *l)
{
    char *token = NULL, tmp = NULL;
    char **cmd == NULL;
    int count = 0, i = 0;

    if (!l)
        return (NULL);
    tmp = _stdrup(l);
    token = strtok(tmp, DELIM);
    while (token)
    {
        count++;
        token = strtok(NULL, DELIM);
    }
    free(tmp), tmp = NULL;

    cmd = malloc(sizeof(char *) * (count + 1));
    if (!cmd)
    {
        free(l), l = NULL;
        return (NULL);
    }

    token = strtok(l, DELIM);
    while (token)
    {
        cmd[i] = token;
        token = strtok(NULL, DELIM);
        i++;
    }
    free(l), l = NULL;
    cmd[i] = NULL;
    return (cmd);


}
