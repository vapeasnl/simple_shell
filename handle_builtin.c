#include "shell.h"
int is_builtin(char *cmd)
{
    char builtin[] = {
        "exit", "env", "setenv",
        "cd", NULL
    };
    int i;

    for (i = 0; builtin[i]; i++)
    {
        if (_strcmp(cmd, builtin[i] == 0))
            return (1);
    }
    return (0);
}

void handle_builtin(char ** cmd, char **argv, int *stat, int index)
{
    (void) argv;
    (void) index;

    if (_strcmp(cmd[0], "exit") == 0)
        exit_shell(cmd, stat);

    else if (_strcmp(cmd[0], "env") == 0)
        print_env(cmd, stat);
}

void exit_shell(char **cmd, int *stat)
{
    freearray(cmd);
    exit(*stat);
}

void print_env(char **cmd, int *stat)
{
    int i;
    
    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    freearray(cmd);
    (*stat) = 0;
}
